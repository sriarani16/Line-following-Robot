int mr1=8;  //motor right 1
int mr2=9;  //motor right 2
int ml1=10;   //motor left 1
int ml2=11; //motor left 2
int sr=6;   //sensor right
int   sl=7;   //sensor left
int svr=0;
int svl=0;
int led=13;
int enr=3; 
int   enl=5;

int vlspeed=100;   
int vrspeed=80; 
int tspeed=70;
int tdelay=20;

void   setup()
{
 pinMode(mr1,OUTPUT);
 pinMode(mr2,OUTPUT);
 pinMode(ml1,OUTPUT);
   pinMode(ml2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sr,INPUT);
 pinMode(sl,INPUT);
   
 delay(5000);
}

void loop()
{
 svr=digitalRead(sr);
 svl=digitalRead(sl);
   
  if(svl==LOW && svr==LOW)
  {
  stop(); 
  }

  if(svl==HIGH   && svr==LOW)
  {
  right(); 
  }
 
  if(svl==LOW && svr==HIGH)
   { 
  left(); 
  }
  
  if(svl==HIGH && svr==HIGH)
   {
  forward(); 
  }
}

void forward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,vrspeed);
  analogWrite (enl,vlspeed);
 } 

void backward()
   {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
   digitalWrite(ml2,HIGH);
  analogWrite (enr,vrspeed);
  analogWrite (enl,vlspeed);
   }

void right()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
   digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,tspeed);
   analogWrite (enl,tspeed);
  delay(tdelay);
 } 

void left()
 {
   digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
   digitalWrite(ml2,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
   delay(tdelay);
}  

void stop()
 {
  analogWrite (enr,0);
  analogWrite   (enl,0);
 }
