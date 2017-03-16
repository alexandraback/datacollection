#include <stdio.h>

#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))
int x, r, c;

bool solve() {
  if (x >= 7) return false;
  if (r * c % x) return false;

  switch (x) {
    case 1:
      return true;
    case 2:
      return max(r, c) >= 2;
    case 3:
      return max(r, c) >= 3 && min(r, c) > 1;
    case 4:
      return max(r, c) >= 4 && min(r, c) > 2;
    case 5:
      return max(r, c) >= 5 && min(r, c) > 2;
    case 6:
      return max(r, c) >= 6 && min(r, c) > 2;
    default:
      return true;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d%d%d", &x, &r, &c);
    printf("Case #%d: %s\n", i, solve() ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
