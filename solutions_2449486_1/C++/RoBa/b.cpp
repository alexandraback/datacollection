#include <cstdio>
#include <string>
using namespace std;

int a[101][101];
bool tmp[101][101];
int m, n;

int main() {
  int T, ca;
  scanf("%d",&T);
  for (ca = 1 ; ca <= T ; ++ca) {
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i < n ; ++i)
      for (int j = 0 ; j < m ; ++j)
        scanf("%d",&a[i][j]);
    int fail = 0;
    while (1) {
      int low = 10000, low2 = 10000;
      for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
          if (a[i][j] < low) {
            low2 = low;
            low = a[i][j];
          } else if (a[i][j] > low && a[i][j] < low2) {
            low2 = a[i][j];
          }
      if (low2 == 10000) break;
      // printf("low:%d low2:%d\n", low, low2);
      for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
          if (a[i][j] == low) {
            tmp[i][j] = 1;
          } else tmp[i][j] = 0;
      for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
          if (tmp[i][j]) {
            // check -
            int k;
            for (k = 0 ; k < m ; ++k)
              if (a[i][k] != low) break;
            if (k == m) {
              for (k = 0 ; k < m ; ++k)
                tmp[i][k] = 0;
              continue;
            }
            // check |
            for (k = 0 ; k < n ; ++k)
              if (a[k][j] != low) break;
            if (k == n) {
              for (k = 0 ; k < n ; ++k)
                tmp[k][j] = 0;
              continue;
            }
            // printf("i:%d j:%d fail\n", i, j);
            fail = 1;
            goto out;
          } 
      for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
          if (a[i][j] == low) a[i][j] = low2;
    }
out:
    printf("Case #%d: ", ca);
    if (fail) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}

