#include <stdio.h>
#include <algorithm>

const int MAXN = 200;

int p[MAXN];

int main() {
  int T, n;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", p + i);
      sum += p[i];
    }
    printf("Case #%d:", tt);
    for (int i = 0; i < n; ++i) {
      double min = 0.0, max = 1.0;
      while (max - min > 1e-9) {
        double mid = (min + max) / 2;
        double org = p[i] + sum * mid;
        double tot = mid;
        for (int j = 0; j < n; ++j) {
          if (i != j) {
            tot += std::max(0.0, (org - p[j]) / sum);
          }
        }
        if (tot > 1.0) max = mid;
        else min = mid;
      }
      printf(" %lf", min * 100);
    }
    puts("");
  }
  return 0;
}
