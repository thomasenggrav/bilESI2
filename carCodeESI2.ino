#include "Car.h"

Car car("NTNU-IOT", "");

float ENCODER_VALUES_PER_MOTOR_TURN = 12.0;
float MOTOR_TURNS_PER_WHEEL_TURN = 75.0;
float MILLIMETERS_PER_WHEEL_TURN = 122.52211349;
float carSpeed = 0;
float avstand = 0;
float carFart = 100;


void setup() {
   car.initCar();
}

void loop() { // ikke fjern denne linjen!
   if (car.data[ENCODERS].flag) {
    carSpeed = car.data[ENCODERS].value / car.data[READ_TIME].value;
    carSpeed /= (ENCODER_VALUES_PER_MOTOR_TURN*MOTOR_TURNS_PER_WHEEL_TURN);
    carSpeed *= MILLIMETERS_PER_WHEEL_TURN;
    carSpeed *= 100;

    car.data[ENCODERS].flag = false;
    car.sendData(1, carSpeed);
  }
  if (car.data[PROXIMITY].flag) {
  int proxData = car.data[PROXIMITY].value;
  car.data[PROXIMITY].flag = false;
  avstand = car.data[PROXIMITY].value;
  car.sendData(2, avstand);
  }
}


// dette er koden for kjøre framover
void w(bool button) { // ikke fjern denne linjen!
   if (button == DOWN) {
      // dette skjer når knappen trykkes ned
      car.drive(carFart, carFart);
   }
   if (button == UP) {
      // dette skjer når knappen slippes opp
      car.drive(0, 0);
   }
}

void a(bool button) { // ikke fjern denne linjen!
   if (button == DOWN) {
     car.drive(-100, 100);
   }
   if (button == UP) {
     car.drive(0, 0);
   }
}

void s(bool button) { // ikke fjern denne linjen!
   if (button == DOWN) {
     car.drive(-carFart, -carFart);
   }
   if (button == UP){
     car.drive(0, 0);
   }
}

void d(bool button) { // ikke fjern denne linjen!
   if (button == DOWN){
     car.drive(100, -100);
   }
   if (button == UP){
     car.drive(0, 0);
   }
}

void e(bool button) { // ikke fjern denne linjen!
   if (button == DOWN){
     car.drive(carFart,carFart/1.6);
   }
   if (button == UP){
     car.drive(0, 0);
   }
}

void q(bool button) { // ikke fjern denne linjen!
    if (button == DOWN){
     car.drive(carFart/1.6, carFart);
   }
   if (button == UP){
     car.drive(0, 0);
   }
}


void triangle(bool button) { // ikke fjern denne linjen!
   carFart+=5;
}

void circle(bool button) { // ikke fjern denne linjen!
   carFart-=5;
}

void square(bool button) { // ikke fjern denne linjen!
   // skriv kode her
}
