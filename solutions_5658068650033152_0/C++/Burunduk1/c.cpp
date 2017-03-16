/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.11
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define IS(a, i) (((a) >> (i)) & 1)

const int N = 30;

int w, h, k;
int num, a[N][N], u[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline void dfs( int x, int y )
{
  if (a[y][x])
    return;
  u[y][x] = 1, num--;
  forn(k, 4)
  {
    int x1 = x + dx[k];
    int y1 = y + dx[k];
    if (0 <= x1 && x1 < w && 0 <= y1 && y1 < h && !u[y1][x1])
      dfs(x1, y1);
  }
}

void solve()
{
  scanf("%d%d%d", &h, &w, &k);
  int ans = h * w;
  forn(p, 1 << (h * w))
  {
    int cnt = 0;
    forn(i, h)
      forn(j, w)
        u[i][j] = 0, cnt += a[i][j] = IS(p, i * w + j);
    num = w * h;
    forn(i, h)
      forn(j, w)
        if (!i || !j || j == w - 1 || i == h - 1)
          dfs(j, i);
    if (cnt < ans && num >= k)
      ans = cnt;
  }
  printf("%d\n", ans);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(i, tn)
  {
    printf("Case #%d: ", i + 1);
    fprintf(stderr, "%d\n", i + 1);
    solve();
  }
  return 0;
}
