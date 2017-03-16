#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int f[2][MAXN];
int best[MAXN][2];
int n, s, p;

void best_cal(int x, int idx)
{
  best[idx][0] = best[idx][1] = -1;
  for (int j, k, i = 0; i <= 10; ++i) {
    for (int d1 = 0; d1 < 3; ++d1) {
      for (int d2 = 0; d2 < 3; ++d2) {
	j = i-d1;
	k = i-d2;
	if (j < 0 || k < 0 || i+j+k != x) continue;

	if (d1 == 2 || d2 == 2)
	  best[idx][1] = i;
	else
	  best[idx][0] = i;
      }
    }
  }
}

void init()
{
  scanf("%d%d%d", &n, &s, &p);
  for (int x, i = 0; i < n; ++i) {
    scanf("%d", &x);
    best_cal(x, i);
  }
}

void solve()
{
  int w = 0;
  memset(f[w], 0, sizeof(f[w]));
  for (int i = 1; i <= n; ++i) {
    memset(f[w^1], 0, sizeof(f[w^1]));
    for (int limit = min(s, i), j = 0; j <= limit; ++j) {
      if (j > 0) {
	f[w^1][j] = f[w][j-1] + (best[i-1][1] >= p);
      }
      if (i > j) {
	f[w^1][j] = max(f[w^1][j], f[w][j]+ (best[i-1][0] >= p));
      }
    }
    w ^= 1;
  }

  printf("%d\n", f[w][s]);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    init();
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
