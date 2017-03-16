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

int a[105][105];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int n, m;
    scanf ("%d %d", &n, &m);

    vector <pair <int, int> > v[101];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf ("%d", &a[i][j]);
        v[a[i][j]].push_back (make_pair (i, j));
      }

    int marki[105] = {0};
    int markj[105] = {0};
    int good = 1;

    for (int x = 1; x <= 100 && good; x++) {
      for (int t = 0; t < (int)v[x].size() && good; t++) {
        int i = v[x][t].first;
        int j = v[x][t].second;
        if (!marki[i] && !markj[j]) {
          bool cani = true;
          for (int ti = 0; ti < n && cani; ti++) {
            if (!marki[ti] && a[ti][j] > x)
              cani = false; 
          }
          if (cani) {
            markj[j] = 1;
            continue;
          }

          bool canj = true;
          for (int tj = 0; tj < m && canj; tj++) {
            if (!markj[tj] && a[i][tj] > x)
              canj = false; 
          }
          if (canj) {
            marki[i] = 1;
            continue;
          }

          good = 0;
        }
      }
    }

    puts (good ? "YES" : "NO");
  }

  return 0;
}
