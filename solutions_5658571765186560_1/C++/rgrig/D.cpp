#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int X, R, C; scanf("%d %d %d", &X, &R, &C);
    int result = X == 1;
    if (R > C) { int x = R; R = C; C = x; }
    if (C == 2) {
      result |=  X == 2;
    } else if (C == 3) {
      result |= X == 2 && R == 2;
      result |= X == 3 && R > 1;
    } else if (C == 4) {
      result |= X == 2;
      result |= X == 3 && R == 3;
      result |= X == 4 && R > 2;
    } else if (C == 5) {
      result |= X == 2 && (R == 2 || R == 4);
      result |= X == 3 && R == 3;
      result |= X == 4 && R == 4;
      result |= X == 5 && R > 2;
    } else if (C == 6) {
      result |= X == 2;
      result |= X == 3 && R > 1;
      result |= X == 4 && (R == 4 || R == 6);
      result |= X == 5 && R == 5;
      result |= X == 6 && R > 3;
    }

    printf("Case #%d: ", t);
    if (result) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }
  }
}
