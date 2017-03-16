#include <stdio.h>
#include <math.h>

long long  getAns(long long  r, long long  t) {
  double delta = (2.0*r-1)*(2.0*r-1)+8.0*t;
  double tmp = (-(2.0*r-1) + sqrt(delta))/4.0;
  long long  res = tmp;
  return res ;
}

int main() {
  int T;
  long long  r, t;
  scanf("%d", &T);
  for (int i = 1;i <= T; ++i) {
    scanf("%lld %lld", &r, &t);
    printf("Case #%d: %lld\n", i, getAns(r, t)); 
  }
  return 0;
}

