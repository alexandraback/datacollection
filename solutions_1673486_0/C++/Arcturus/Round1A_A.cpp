#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
  
int main(){
  int jcase;
  int typed, total;
  double ptyped[10];
  double pfalse[10];
  double correct;
  double best, temp;
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    best = 0;
    scanf("%d %d", &typed, &total);
    
    for(int i=0; i<typed; i++) scanf("%lf", &ptyped[i]);
    for(int i=0; i<typed; i++) ptyped[i] = 1-ptyped[i];
    
    for(int i=0; i<typed; i++){
      pfalse[i] = ptyped[i];
      for(int j=0; j<i; j++){
        pfalse[i] *= (1-ptyped[j]);
      }
    }
    correct = 1-ptyped[0];
    for(int i=1; i<typed; i++) correct *= (1-ptyped[i]);
    
    //prob enter
    temp = 0;
    for(int i=0; i<typed; i++){
      temp += pfalse[i]*(2 + total);
    }
    temp += correct*(2+total);
    best = temp;
    //printf("enter = %lf\n", temp);
    
    //prob backspace;
    for(int i=0; i<typed; i++){ //num bksp
      temp = 0;
      for(int j=0; j<typed; j++){ //loc of err
        if(i<=j) temp += pfalse[j]*(2*(typed-i) + total-typed + 1);
        else temp += pfalse[j]*(2*(typed-i) + 2*total-typed + 2);
      }
      temp += correct*(2*(typed-i) + total-typed + 1);
    //  printf("bksp%d = %lf\n", i, temp);
    
      if(best > temp) best = temp;
    }
    
    //prob continue
    temp = 0;
    for(int i=0; i<typed; i++){
      temp += pfalse[i]*(total-typed+total+2);
    }
    temp += correct*(total-typed + 1);
    //printf("cont = %lf\n", temp);
    if(best > temp) best = temp;
    
    printf("Case #%d: %lf\n", icase+1,best);
  }
}
  
