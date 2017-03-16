#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int b[1010];
int d[1010];
int c[1010];

int main() {
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &b[i]), ++d[b[i]], c[i] = 1;

    for (bool ok = true; ok;){
      ok = false;
      for (int i = 1; i <= n; ++i) if (d[i] == 0) {
        c[b[i]] = max(c[b[i]], c[i] + 1);
        --d[b[i]];
        c[i] = 0;
        d[i] = -1;
        ok = true;
        //printf(">%d\n", i);
      }
    }

    int best = 0;

    for (int i = 1; i <= n; ++i)
      if (b[b[i]] == i && i < b[i])
        best += c[i] + c[b[i]];

    int vis[1010];
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) if (d[i] != -1 && b[b[i]] != i && !vis[i]) {
      int cnt = 0;
      int x = i;
      while (!vis[x])
        vis[x] = cnt++, x = b[x];
      cnt -= vis[x];
      if (cnt > best) best = cnt;
    }

    printf("Case #%d: %d\n", t, best);
  }
  return 0;
}
