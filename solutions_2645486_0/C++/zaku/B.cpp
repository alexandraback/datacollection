#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())

typedef long long LL;

#ifdef __linux__
#define FMT "%lld"
#else
#define FMT "%I64d"
#endif

const int kMaxN = 10010;

int n, E, R;
int V[kMaxN];
int imp[kMaxN];

void solve1()
{
  int idx = n-1;
  memset(imp, 0, sizeof(imp));
  imp[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    if (V[i] >= V[idx]) {
      imp[i] = 1;
      idx = i;
    }
  }

  if (R > E) R = E;
  LL result = 0, e = E;
  for (int i = 0; i < n; ++i) {
    if (imp[i]) {
      result += e * V[i];
      e = R;
    } else {
      result += R * V[i];
      if (e + R < E) e += R; else e = E;
    }
  }

  printf(FMT "\n", result);
}

void solve()
{
  static LL f[2][10];

  int w = 0;
  memset(f, 0xff, sizeof(f));
  f[w][E] = 0;
  for (int i = 0; i < n; ++i) {
    memset(f[w^1], 0xff, sizeof(f[w^1]));
    for (int j = 0; j <= E; ++j) {
      if (f[w][j] < 0) continue;
      for (int l = 0; l <= j; ++l) {
	f[w^1][min(E, j-l+R)] = max(f[w][j] + l * V[i], f[w^1][min(E, j-l+R)]);
      }
    }
    w ^= 1;
  }

  LL result = 0;
  for (int i = 0; i <= E; ++i) result = max(result, f[w][i]);
  printf(FMT "\n", result);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf("%d%d%d", &E, &R, &n);
    for (int i = 0; i < n; ++i) scanf("%d", V + i);
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
