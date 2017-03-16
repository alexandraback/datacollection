#include<stdio.h>
#include<stdlib.h>

const long long MAX = 1000000001;
int number, test_case;
long long result=0;
long long radius, paint;

bool check(long long arg, long long r, long long p){
  long long value = 2*arg*(arg-1) + (2*r+1)*arg;
  return p < value;
}

int main(){
  scanf("%d\n", &number);
  for(int i=0; i<number; ++i){
    test_case = i+1;
    scanf("%lld", &radius);
    scanf("%lld", &paint);
    long long max = paint/radius;
    if(max > MAX){
      max = MAX;
    }
    long long begin = 0;
    long long end = max;
    long long center;
    while(end>begin){
      center = (begin+end)/2+1;
      if(check(center, radius, paint)){
	end = center-1;
      }
      else{
	begin=center;
      }
    }
    result = end;
    printf("Case #%d: ", test_case);
    printf("%lld\n", result);
  }
  return 0;
}
