#include <cstdio>
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int tc = 1; tc <= T; ++tc) {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);

    double best = numeric_limits<double>::max();
    double rate = 2.0, t = 0.0;

    for (;;) {
      double cur = t + X / rate;
      if (cur >= best) break;

      t    += C / rate;
      rate += F;
      best = cur;
    }

    printf("Case #%d: %.8lf\n", tc, best);
  }

  return EXIT_SUCCESS;
}
