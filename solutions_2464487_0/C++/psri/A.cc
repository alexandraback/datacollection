#include <stdio.h>
typedef unsigned long long ul;
int main(){
  int N;
  scanf("%d", &N);
  ul r, t;
  for(int I = 1; I <= N; ++I){
    scanf("%llu %llu", &r, &t);
    ul low = 1, high = t+2;
    while(high - low > 1){
      ul mid = (high + low)/2;
      if(2*mid-1+2*r <= t/mid){
	low = mid;
      }
      else
	high = mid;
    }
    printf("Case #%d: %llu\n", I, low);
  }
  return 0;
}
