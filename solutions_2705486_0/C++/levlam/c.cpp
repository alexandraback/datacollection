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

char s[5005], t[105];
int d[5005][5];

set <string> s0[11], s1[11], s2[11];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);

  FILE *f = fopen ("garbled_email_dictionary.txt", "r");
  while (!feof (f) && fscanf (f, "%s", s)) {
    int l = strlen (s), ll = l;
    assert (l <= 10);
    s0[ll].insert (s);

    for (int i = 0; i < l; i++) {
      memcpy (t, s, l + 1);
      t[i] = '?';
      s1[ll].insert (t);
    }

    for (int i = 0; i + 5 < l; i++) {
      for (int j = i + 5; j < l; j++) {
        memcpy (t, s, l + 1);
        t[i] = t[j] = '?';
        s2[ll].insert (t);
      }
    }
  }

  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    scanf ("%s", s);
    int n = strlen (s);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j <= n; j++) {
        d[j][i] = n;
      }
    }
    d[0][0] = 0;

    for (int x = 0; x < n; x++) {
    for (int dx = 0; dx < 5; dx++) {
      for (int l = 1; l <= 10 && x + l <= n; l++) {
        int nx = x + l, ndx; 

        memcpy (t, s + x, l);
        t[l] = 0;
        
        ndx = max (0, dx - l);
        if (s0[l].count (t) && d[nx][ndx] > d[x][dx]) {
          d[nx][ndx] = d[x][dx];
        }

        for (int i = dx; i < l; i++) {
          memcpy (t, s + x, l);
          t[i] = '?';
          t[l] = 0;

          ndx = max (0, 5 - (l - i));
          if (s1[l].count (t) && d[nx][ndx] > d[x][dx] + 1) {
            d[nx][ndx] = d[x][dx] + 1;
          }
        }

        for (int i = dx; i + 5 < l; i++) {
          for (int j = i + 5; j < l; j++) {
            memcpy (t, s + x, l);
            t[i] = t[j] = '?';
            t[l] = 0;

            ndx = max (0, 5 - (l - j));
            if (s2[l].count (t) && d[nx][ndx] > d[x][dx] + 2) {
              d[nx][ndx] = d[x][dx] + 2;
            }
          }
        }
      }
    }
    }
    int res = n;
    for (int i = 0; i < 5; i++) {
      res = min (res, d[n][i]);
    }

    printf ("%d\n", res);
  }

  return 0;
}
