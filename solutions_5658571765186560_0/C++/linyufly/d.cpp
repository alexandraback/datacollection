#include <cstdio>

#include <algorithm>

using namespace std;

void g_win() {
  printf("GABRIEL\n");
}

void r_win() {
  printf("RICHARD\n");
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    printf("Case #%d: ", t);

    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    if (r > c) {
      swap(r, c);
    }

    if (x >= 7
        || r * c % x != 0
        || x > c
        || (x + 1) / 2 > r
        || (x > 3 && x >= 2 * r)) {
      r_win();
    } else {
      g_win();
    }
  }

  return 0;
}

