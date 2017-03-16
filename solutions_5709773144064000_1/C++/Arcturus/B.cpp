#include <stdio.h>

int main(){
  int jcase;
  double C, F, X;
  double best, time, rate, needTime;
  
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%lf %lf %lf", &C, &F, &X);
    
    best = X/2;
    time = 0;
    rate = 2;
    
    while(1){
      time += C/rate;
      rate += F;
      needTime = time + X/rate;
      if(needTime < best) best = needTime;
      else break;
    }
    
    printf("Case #%d: %.7lf\n", icase+1, best);
  }
  return 0;
}
