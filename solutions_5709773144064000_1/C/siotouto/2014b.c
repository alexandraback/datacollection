#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FALSE 0
#define TRUE 1

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main(void)
{
  int T,t;
  double C,F,X,tmpans,newans,buytime,cps;
  scanf("%d\n",&T);
  t=T;
  while(t--){
    scanf("%lf %lf %lf",&C,&F,&X);
    cps=2.0;
    buytime=0.0;
    tmpans=X/cps+buytime;
    while(1){
      buytime+=C/cps;
      cps+=F;
      newans=X/cps+buytime;
      if(tmpans<=newans){
        printf("Case #%d: %lf\n",T-t,tmpans);
        break;
      }
      tmpans=newans;
    }
  } 
  return 0;
}
