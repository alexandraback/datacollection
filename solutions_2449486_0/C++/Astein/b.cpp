#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[101][101];
int h[101][101];

int main() {
  int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; ++cn)  {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    // set
    for (int i = 0; i < n; ++i) {
      int maxh = -1;
      for (int j = 0; j < m; ++j) 
        maxh = max(maxh, a[i][j]);
      for (int j = 0; j < m; ++j) 
        h[i][j] = maxh;
    }

    for (int i = 0; i < m; ++i) {
      int maxh = -1;
      for (int j = 0; j < n; ++j) 
        maxh = max(maxh, a[j][i]);
      for (int j = 0; j < n; ++j)
        h[j][i] = min(h[j][i], maxh);
    }
    // check
    bool isok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] != h[i][j]) isok = false;
      }
    }
    printf("Case #%d: %s\n", cn, (isok ? "YES" : "NO"));
  }
}
