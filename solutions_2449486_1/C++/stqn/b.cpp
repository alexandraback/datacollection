#include <algorithm>
#include <cstdio>

int nextInt() { int tmp; scanf("%d", &tmp); return tmp; }

int t = 0;

void solve()
{
  int a[128][128] = {};
  int row[128] = {};
  int col[128] = {};

  int N = nextInt();
  int M = nextInt();
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      a[y][x] = nextInt();
      row[y] = std::max(row[y], a[y][x]);
      col[x] = std::max(col[x], a[y][x]);
    }
  }

  try {
    for (int y = 0; y < N; ++y)
      for (int x = 0; x < M; ++x)
        if (a[y][x] < row[y] && a[y][x] < col[x])
          throw "NO";
    throw "YES";
  } catch (char *s) {
    printf("Case #%d: %s\n", ++t, s);
  }
}

int main()
{
  int T = nextInt();
  while (T --> 0)
    solve();

  return 0;
}
