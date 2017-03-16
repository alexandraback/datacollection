#include <stdio.h>

int main() {
  int T;
  double C, F, X;
  double p;
  double result;
  scanf("%d", &T);
  for (int N = 0; N < T; ++N) {
    scanf("%lf%lf%lf", &C, &F, &X);
    p = 2;
    result = 0;
    while(C/p + X/(p+F) < X/p) {
      result += C/p;
      p += F;
    }
    result += X/p;
    printf("Case #%d: %.7lf\n", N+1, result);
  }
  return 0;
}
