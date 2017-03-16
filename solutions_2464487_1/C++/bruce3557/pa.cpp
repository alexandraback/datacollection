#include <stdio.h>
#include <string.h>
#include <math.h>

const double PI = acos(-1);

double r, t;

int main() {
  int kas = 0;
  int T;

  scanf("%d", &T);
  while(T--) {
    scanf("%lf%lf", &r, &t);
    
    long long st = 1;
    long long ed = t + 1;
    while(st < ed) {
      long long mid = (st + ed) >> 1;
      double x = (double) mid * (double) (2 * mid - 1) + 2 * mid * r;
      if(x <= t)  st = mid + 1;
      else        ed = mid;
    }
    
    printf("Case #%d: %lld\n", ++kas, ed - 1);
  }

  return 0;
}

