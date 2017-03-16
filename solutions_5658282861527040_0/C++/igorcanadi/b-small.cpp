#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int sol = 0;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if ((i & j) < k) ++sol;
      }
    }
    printf("Case #%d: %d\n", tt, sol);
  }
  return 0;
}
