#include <stdio.h>

int main() {
  int T, D, G[1001];
  scanf("%d", &T);
  int tc;
  for (tc = 1; tc <= T; tc++) {
    int i;
    for (i = 0; i < 1001; i++) {
      G[i] = 0;
    }
    scanf("%d", &D);
    while (D--) {
      int tmp;
      scanf("%d", &tmp);
      G[tmp]++;
    }
    int best = 1000;
    int at_most;
    for (at_most = 1; at_most < 1001; at_most++) {
      int score = 0;
      for (i = at_most + 1; i < 1001; i++) {
        score += G[i] * (i / at_most + (i % at_most > 0 ? 1 : 0) - 1);
      }
      if (best > at_most + score) {
        best = at_most + score;
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
