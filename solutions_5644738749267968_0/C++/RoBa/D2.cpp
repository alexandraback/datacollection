#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1010;
double a[MAXN], b[MAXN];
int vis[MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
      scanf("%lf", a+i);
    for (int i = 0 ; i < n ; ++i)
      scanf("%lf", b+i);
    sort(a, a+n);
    sort(b, b+n);
    vector<double> va, vb;
    memset(vis, 0, sizeof(vis));
    int old_win = 0;
    for (int i = 0 ; i < n ; ++i) {
      int flg = 0;
      for (int j = 0 ; j < n ; ++j)
        if (vis[j] == 0 && b[j] > a[i]) {
          va.push_back(a[i]);
          vb.push_back(b[j]);
          vis[j] = 1;
          flg = 1;
          break;
        }
      if (!flg) ++old_win;
    }
/*
    for (int i = 0 ; i < va.size() ; ++i)
      printf(" %.3lf", va[i]);
    printf("\n");
    for (int i = 0 ; i < vb.size() ; ++i)
      printf(" %.3lf", vb[i]);
    printf("\n");
*/
    int new_win = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0 ; i < n ; ++i) {
      double minb = 2.0;
      int minj;
      for (int j = 0 ; j < n ; ++j)
        if (vis[j] == 0 && b[j] < minb) {
          minb = b[j];
          minj = j;
        }
      if (a[i] > minb) {
        vis[minj] = 1;
        ++new_win;
      } else {
        double maxb = -1.0;
        int maxj;
        for (int j = 0 ; j < n ; ++j)
          if (vis[j] == 0 && b[j] > maxb) {
            maxb = b[j];
            maxj = j;
          }
        vis[maxj] = 1;
      }
    }

    printf("Case #%d: %d %d\n", ca, new_win, old_win);
  }
  return 0;
}

