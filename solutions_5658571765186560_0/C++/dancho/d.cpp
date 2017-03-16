#include <cstdio>
#include <cstring>

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    bool cov = false;
    if (x == 1) {
      cov = true;
    } else if (x == 2) {
      if ((r * c) % 2 == 0) {
        cov = true;
      }
    } else if (x == 3) {
      if ((r * c) % 3 == 0) {
        if (r >= 2 && c >= 2) {
          cov = true;
        }
      }
    } else if (x == 4) {
      if (r >= 3 && c >= 3 && (r * c) % 4 == 0) {
        cov = true;
      }
    }
    printf("Case #%d: %s\n", t, cov ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
