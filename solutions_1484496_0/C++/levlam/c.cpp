#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int a[505];
int b[1<<21];

int sum[1<<20];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: ", tn);
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
      scanf("%d", &a[i]), s += a[i], b[1<<i] = a[i];

    for (int i = 1; i < (1 << n); i++) {
      sum[i] = sum[i & (i - 1)] + b[i - (i & (i - 1))];
    }

    int i;
    int ok = 0;
    for (i = 1; i < (1 << n) && !ok; i++) {
      int mask = ((1 << n) - 1) & ~i, targ = sum[i];
      for (int ii = mask; ii > 0 && !ok; ii = (ii - 1) & mask)
        if (sum[ii] == targ) {
          printf ("\n");
          for (int j = 0; j < n; j++)
            if (((ii >> j) & 1) == 1) {
              printf ("%d ", a[j]);
            }
          printf ("\n");

          for (int j = 0; j < n; j++)
            if (((i >> j) & 1) == 1) {
              printf ("%d ", a[j]);
            }
          printf ("\n");
          ok = 1;
        }
    }
    if (!ok) {
      printf ("impossible");
    }
  }

  return 0;
}
