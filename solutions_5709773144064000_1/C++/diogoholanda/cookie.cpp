#include <stdio.h>
#include <string.h>

int T;
double C,F,X;
double minimo, prod, t, add;

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    scanf(" %lf %lf %lf", &C, &F, &X);
    prod = 2.0;
    minimo = X/prod;
    t = 0;
    while(true){
      t+=C/prod;
      prod+=F;
      add = X/prod;
      if(t+add < minimo){
        minimo = t+add;
      }
      else{
        break;
      }
    }
    printf("Case #%d: %.7lf\n", u, minimo);
  }
  return 0;
}
