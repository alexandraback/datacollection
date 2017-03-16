#include<stdio.h>

long long gcd(long long a, long long b) {
  long long t;
  while(a>0) {
    t = a;a = b%a;b = t;
  }
  return b;
}

int main() {
  int t,T,i;
  long long x,y,g;
  scanf("%d",&T);
  for(t=1;t<=T;t++) {
    scanf("%lld/%lld",&x,&y);
    g = gcd(x,y);
    x /= g; y /= g;
    if((y-1)&y) {printf("Case #%d: impossible\n",t);continue;}
    for(i=0;y%2==0 && y>x;i++) {y/=2;}
    printf("Case #%d: %d\n",t,i);
  }
  return 0;
}
