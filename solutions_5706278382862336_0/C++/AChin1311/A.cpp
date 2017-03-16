#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}
int check(int a){
  while(a%2 == 0)
    a/=2;
  if(a == 1) return 1;
  else return 0;
}
int main(void){
  int T, t;
  scanf("%d", &t);
  for(T = 1; T <= t; T++){
    int a, b, p;
    scanf("%d/%d", &a, &b);
    p = gcd(a, b);
    a = a/p; b = b/p;
    
    if(check(b) != 1){
      printf("Case #%d: impossible\n", T);
    }
    else{
      int g = 0;
      while(a < b){
        b = b/2;
        g++;
      }
      if(g == 0)
        printf("Case #%d: impossible\n", T);
      else
        printf("Case #%d: %d\n", T, g);
  
    }
  }
  return 0;
}