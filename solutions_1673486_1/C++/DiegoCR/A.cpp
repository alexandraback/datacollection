#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

double prob[100100];
double mem[100100];

int main(){
    
    int nc,tc=0,a,b;
    double espmen,cont,esp;
    //freopen("a2.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>nc;
    while(nc--){
      scanf("%d %d",&a,&b);
      tc++;
      cont = 1;
      for(int i=0;i<a;i++){
              cin>>prob[i];
              cont*=prob[i];
              }
      espmen = b+2;
      //opcion1
      esp = (cont*(b-a+1) + (1.0-cont)*(b+b-a+2));
      if(espmen>esp) espmen = esp;
      //opcion2
      for(int i=a-1;i>=0;i--){
              cont /= prob[i];
              esp = (cont*((a-i)+(a-i)+(b-a)+1) + (1.0-cont)*((a-i)+(a-i)+(b-a)+1+(b+1)));
              if(espmen>esp) espmen = esp;
              }
      printf("Case #%d: %.6f\n",tc,espmen);
      }
    
    }
