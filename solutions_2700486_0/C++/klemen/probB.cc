#include <stdio.h>

int T, N, X, Y;
int LV, POS;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d %d", &N, &X, &Y);
    // determine level and position
    if (X >= 0) {
      LV = (Y + X) / 2;
    }
    else {
      LV = (Y - X) / 2;
    }
    POS = X;
    // determine structure
    int full = 0, remains = N;
    int side = 1;
    int current = 1;
    while (remains >= current) {
      full++;
      remains -= current;
      current = 2 * (++side) + 1;
      side++;
    }
    double rv = 0.5;
    if (LV < full) {
      rv = 1.0;
    }
    else if (LV > full) {
      rv = 0.0;
    }
    else {
//      printf("# %d %d\n", full, remains);
      int all = 0;
      int ok = 0;
      for (int left = 0; left < side; left++) {
        int right = remains - left;
        if (right >= 0 && right < side) {
//          printf("## %d %d\n", left, right);
          int factor = left < right ? left : right;
          factor = 1 << factor;
          all += factor;
          if (POS < 0) {
            int pp = (side - 1) + POS;
            if (pp < left)
              ok += factor;
          }
          else {
            int pp = (side - 1) - POS;
            if (pp < right)
              ok += factor;
          }
        }
      }
//      printf("### %d %d\n", ok, all);
      rv = (double)ok / (double)all;
    }
    printf("Case #%d: %lf\n", t + 1, rv);
  }
}
