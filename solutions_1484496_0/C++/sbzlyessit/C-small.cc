#include <stdio.h>

int a[100];
int n;

int resultx, resulty;

bool dfs(int x, int sx, int y, int sy, int step) {
  if (sx > 0 && sx == sy) {
    resultx = x, resulty = y;
    return true;
  }
  if (step == n) return false;
  if (dfs(x, sx, y, sy, step + 1)) return true;
  if (dfs(x | (1 << step), sx + a[step], y, sy, step + 1)) return true;
  if (dfs(x, sx, y | (1 << step), sy + a[step], step + 1)) return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    printf("Case #%d:\n", tt);
    if (dfs(0, 0, 0, 0, 0)) {
      bool printed = false;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & resultx) {
          if (printed) putchar(' ');
          printf("%d", a[i]);
          printed = true;
        }
      }
      puts("");
      printed = false;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & resulty) {
          if (printed) putchar(' ');
          printf("%d", a[i]);
          printed = true;
        }
      }
      puts("");
    } else {
      puts("Impossible");
    }
  }
  return 0;
}
