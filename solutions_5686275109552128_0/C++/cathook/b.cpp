#include <stdio.h>

#include <queue>
#include <algorithm>

const int DMAX = 1000;
const int PMAX = 1000;


int main() {
  int T, t;
  for (scanf("%d", &T), t = 1; t <= T; ++t) {
    static int d, p[DMAX];
    scanf("%d", &d);
    for (int i = 0; i < d; ++i) {
      scanf("%d", &(p[i]));
    }
    int ans = PMAX;
    for (int i = 1; i <= PMAX; ++i) {
      int split = 0;
      for (int j = 0; j < d; ++j) {
        split += (p[j] + i - 1) / i - 1;
      }
      ans = std::min(ans, split + i);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
