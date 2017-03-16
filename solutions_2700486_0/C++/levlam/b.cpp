#include <cassert>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

double p[10000], q[10000];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);

  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int n, x, y;
    scanf ("%d%d%d", &n, &x, &y);
    assert ((x + y) % 2 == 0);
    if (x < 0) {
      x = -x;
    }
    int t = (x + y) / 2;
    int l = 2 * t * t  - t;
//    cerr << t << " " << l << " " << n << endl;
    if (n <= l) {
      printf ("0.0\n");
      continue;
    }

    int r = 2 * (t + 1) * (t + 1)  - (t + 1);
    if (n >= r) {
      printf ("1.0\n");
      continue;
    }

    n -= l;
    assert (1 <= n && n <= 4 * t);

    memset (p, 0, (n + 2) * sizeof (double));
    p[0] = 1.0; 

//    cerr << "n = " << n << endl;

    for (int i = 1; i <= n; i++) {
      memset (q, 0, (i + 1) * sizeof (double));
      for (int j = 0; j < i && j <= 2 * t; j++) {
        int k = i - 1 - j;
        if (k <= 2 * t) {
          if (j == 2 * t) {
            q[j] += p[j];
          } else if (k == 2 * t) {
            q[j + 1] += p[j];
          } else {
            p[j] *= 0.5;
            q[j] += p[j];
            q[j + 1] += p[j];
          }
        } else {
          assert (p[j] < 1e-100);
        }
      }
      memcpy (p, q, (i + 1) * sizeof (double));
    }

    double p1 = 0.0, p2 = 0.0;
    for (int j = 0; j <= n && j <= 2 * t; j++) {
//      fprintf (stderr, "%lf(%d) ", p[j], j);
      if (j > y) {
        p2 += p[j];
      }
      p1 += p[j];
    }
//    fprintf (stderr, "\n");

    assert (fabs (p1 - 1.0) < 1e-9);

    printf ("%.20lf\n", p2);
  }

  return 0;
}
