#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int D; scanf("%d", &D);
    int P[1000];
    for (int i = 0; i < D; ++i) scanf("%d",&P[i]);
    int best_time = 0x3fffffff;
    for (int h = 1; h <= 1000; ++h) {
      int this_time = h;
      for (int i = 0; i < D; ++i) this_time += (P[i] - 1) / h;
      best_time = min(best_time, this_time);
    }
    printf("Case #%d: %d\n", t, best_time);
  }
}
