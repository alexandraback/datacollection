#include <stdio.h>
#define MAX 100001

double p[MAX];

double calc(int a, int b) {
  double res = b+2;
  double x = 1;
  for (int i = 0;i <= a; ++i) {
    if (i > 0)
      x *= p[i-1];
    double tmp = x*(b-a+1+2*a-2*i)+(1-x)*(2*b-a+2+2*a-2*i);
    if (tmp < res) res = tmp;
  }
  return res;
}

int main() {
  int t, a, b;
  scanf("%d", &t);
  for (int i = 1;i <= t; ++i) {
    scanf("%d %d", &a, &b);
    for (int j = 0;j < a; ++j) {
      scanf("%lf", &p[j]);
    }
    printf("Case #%d: %.6f\n", i, calc(a, b));
  }
}
