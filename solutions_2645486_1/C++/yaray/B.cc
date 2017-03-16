#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdint.h>
typedef int64_t i64;

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

const int MAXN = 10000;
int v[MAXN];
i64 R, E;

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

i64 RL()
{
  i64 x;
  scanf("%" SCNd64, &x);
  return x;
}

i64 f(int l, int r, i64 beg, i64 end)
{
  if (l == r) return 0;
  int mi = max_element(v + l, v + r) - v;
  i64 miE = min(E, beg + (mi - l) * R);
  i64 use = max(min(miE + (r - mi) * R - end, miE), i64(0));
  return f(l, mi, beg, miE) + v[mi] * use + f(mi + 1, r, min(miE - use + R, E), end);
}

int main()
{
  int cases = RI();
  REP1(cc, cases) {
    E = RL();
    R = RL();
    int N = RI();
    REP(i, N)
      v[i] = RI();
    printf("Case #%d: %" PRId64"\n", cc, f(0, N, E, 0));
  }
}
