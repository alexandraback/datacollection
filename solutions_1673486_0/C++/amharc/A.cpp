#include <cstdio>
#include <algorithm>

double pr[1000000];

int main() {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; ++tc) {
    int A, B;
    scanf("%d%d", &A, &B);
    double enter_now = 2 + B;
    double product = 1;
    double minimum = std::min<double>(enter_now, A + B + 1);

    for(int i = 0; i < A; ++i) {
      double prob;
      scanf("%lf", &prob);

      product *= prob;
      double expected = product * (A - (i + 1) + B - (i + 1) + 1) +  (1 - product) * (A - (i + 1) + B - (i + 1) + 1 + B + 1);

      if(expected < minimum)
        minimum = expected;
    }

    printf("Case #%d: %lf\n", tc, minimum);
  }
  return 0;
}
