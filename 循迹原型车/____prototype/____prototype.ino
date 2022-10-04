#include<Servo.h>
Servo myservo_1,myservo_2;
const int Trig=2;
const int Echo=4;
const int R=A5;
const int L=A0;
int L_val=0;
int R_val=0;
long distance, Time;
int zuozhi=1600;
int youzhi=1400;
int Stop=1500;
int youzhuan=1750;
int zuozhuan=1250;





void setup() {
 Serial.begin(9600);
 pinMode(Trig,OUTPUT);
 pinMode(Echo,INPUT);
 pinMode(L,INPUT);
 pinMode(R,INPUT);
 myservo_1.attach(9);
 myservo_2.attach(12);
  
  

}

void loop() {
 L_val=analogRead(L);
 R_val=analogRead(R);
 Serial.println(L_val);
 Serial.println(R_val);
 //循迹
 if(L_val<220&R_val<220){
 myservo_1.writeMicroseconds(zuozhi);
 myservo_2.writeMicroseconds(youzhi);
 }
 if(L_val>=220&R_val<220){
  myservo_1.writeMicroseconds(Stop);
  myservo_2.writeMicroseconds(zuozhuan);
  delay(20);
 }
 if(R_val>=220&L_val<220){
  myservo_2.writeMicroseconds(Stop);
  myservo_1.writeMicroseconds(youzhuan);
  delay(20);
 }
 //避障
 //digitalWrite(Trig,LOW);
 delay(2);
 digitalWrite(Trig,HIGH);
 delay(20);
 digitalWrite(Trig,LOW);
 Time=pulseIn(Echo,HIGH);
 distance=Time/58;
if(distance<=15){
  myservo_1.writeMicroseconds(youzhuan);
  myservo_2.writeMicroseconds(Stop);
  delay(400);
  myservo_1.writeMicroseconds(zuozhi);
  myservo_2.writeMicroseconds(youzhi);
  delay(200);
  myservo_2.writeMicroseconds(zuozhuan);
  myservo_1.writeMicroseconds(Stop);
  delay(400);
  myservo_1.writeMicroseconds(Stop);
  myservo_2.writeMicroseconds(zuozhuan);
  delay(400);
  myservo_1.writeMicroseconds(zuozhi);
  myservo_2.writeMicroseconds(youzhi);
  delay(400); 
 }
}
 
  
