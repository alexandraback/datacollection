#include <cstdio>
#include <cstring>

const int MAXN = 100;
bool del[MAXN][MAXN];
int T, n, m, a[MAXN][MAXN];
bool solve()
{
  memset(del ,0, sizeof(del));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i][j]);
  for (int min, x, y; ; )
  {
    min = 0x7FFFFFFF;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (!del[i][j] && a[i][j] < min)
          min = a[x = i][y = j];
    if (min == 0x7FFFFFFF) return true;
    bool row = true, col = true;
    for (int j = 0; j < m && row; ++j) row = del[x][j] || a[x][j] == min;
    for (int i = 0; i < n && col; ++i) col = del[i][y] || a[i][y] == min;
    if (row) for (int j = 0; j < m; ++j) del[x][j] = true;
    if (col) for (int i = 0; i < n; ++i) del[i][y] = true;
    if (!row && !col) return false;
  }
}
int main()
{
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; ++testcase)
    printf("Case #%d: %s\n", testcase, solve() ? "YES" : "NO");
}
