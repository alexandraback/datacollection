#include <cstdio>

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    double C, F, X;
    scanf("%lf%lf%lf",&C,&F,&X);
    double best = 1e100;
    double rate = 2.0, tim = 0.0;
    while (1) {
      double tmp = tim + X / rate;
      if (tmp < best) best = tmp;
      else break;
      tim += C / rate;
      rate += F;
    }
    printf("Case #%d: %.10lf\n", ca, best);
  }
  return 0;
}

