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

int a[205];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d:", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int n, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]), s += a[i];

    for (int i = 0; i < n; i++) {
      double l = 0.0, r = 1.0;
      for (int t = 0; t < 100; t++) {
        double m = (l + r) / 2, all = m;
        for (int j = 0; j < n; j++)
          if (j != i) {
            all += max((a[i] - a[j] + s * m) * 1.0 / s, 0.0);
          }
        if (all >= 1) {
          r = m;
        } else {
          l = m;
        }
      }
      printf (" %.6lf", l * 100);
    }
    printf ("\n");
  }

  return 0;
}
