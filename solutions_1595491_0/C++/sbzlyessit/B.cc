#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    int left = 0, tot = 0, t;
    int N, S, p;
    scanf("%d%d%d", &N, &S, &p);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &t);
      if (t / 3 + (t % 3 != 0) >= p) {
        ++tot;
      } else if (t > 1 && (t - 2) / 3 + 2 >= p && S > 0) {
        ++tot;
        --S;
      }
    }
    printf("Case #%d: %d\n", tt, tot);
  }
  return 0;
}
