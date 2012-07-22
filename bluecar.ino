/*
@author: zhe.zhu@alibaba-inc.com
@refer: http://www.flamingoeda.com/2009/04/19/arduino-l298n-%E7%94%B5%E6%9C%BA%E9%A9%B1%E5%8A%A8%E6%89%A9%E5%B1%95%E6%9D%BF/
@desc: arduino code for bluetooth car
*/

//serial(bluetooth) input
int ipt;

// motor A
int dir1PinA = 13;
int dir2PinA = 12;
int speedPinA = 10;

// motor B
int dir1PinB = 11;
int dir2PinB = 8;
int speedPinB = 9;

//car speed
int speed;
//left or right
int dirLR;
//forward or backward
int dirFB;

void setup(){
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

  speed = 255;
  dirFB = 0;
  dirLR = 0;
  
  Serial.begin(9600);
}

void loop(){
  ipt = Serial.read();
  /*
    w:119
    s:115
    a:97
    d:100
    z:122
  */

  if ( ipt != -1) {
    Serial.println(ipt);
  }
  
  if ( ipt == 'w' ){
    dirFB = 1;
    Serial.println(dirFB);
  } 
  
  if ( ipt == 's' ){
    dirFB = -1;
    Serial.println(dirFB);
  }
  
  if ( ipt == 'a') {
    dirLR = 1;
    Serial.println(dirLR);
  } 
  
  if ( ipt == 'd'){
    dirLR = -1;
    Serial.println(dirLR);
  } 
  
  //z stop everything
  if ( ipt == 'z' ){
    dirFB = 0;
    dirLR = 0;
    Serial.println(dirFB);
    Serial.println(dirLR);
  }
  
  //for beep function in the furture
  if ( ipt == 'b'){
    
  }
  
  //motor function
  if ( 1 == dirLR ) {
    Serial.print('4');
    analogWrite(speedPinB, speed);
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
  } else if ( -1 == dirLR ){
    Serial.print('5');
    analogWrite(speedPinB, speed);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
  } else  if ( 0 == dirLR ){
    Serial.print('6');
    analogWrite(speedPinB, 0);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, LOW);
  }
  
  if ( 1 == dirFB ) {
    Serial.print('1');
    analogWrite(speedPinA, speed);
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
  } else if ( -1 == dirFB ){
    Serial.print('2');
    analogWrite(speedPinA, speed);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
  } else if ( 0 == dirFB ){
    Serial.print('3');
    analogWrite(speedPinA, 0);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, LOW);
  }
  
  Serial.println();
}
