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

int a[105];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);

    int x, n;
    scanf ("%d %d", &x, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort (a, a + n);

    if (x == 1) {
      printf ("%d\n", n);
      continue;
    }

    int ans = 100;
    for (int l = 0; l <= n; l++) {
      int res = n - l, j = 0;
      int cur = x;
      while (j < l) {
        while (j < l && a[j] < cur) {
          cur += a[j];
          j++;
        }
        if (j < l) {
          cur += cur - 1;
          res++;
        }
      }
      if (res < ans) {
        ans = res;
      }
    }

    printf ("%d\n", ans);

    fprintf (stderr, "Case #%d: \n", tn);
  }

  return 0;
}
