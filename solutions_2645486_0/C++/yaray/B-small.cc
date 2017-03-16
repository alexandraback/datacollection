#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdint.h>
typedef int64_t i64;

#include <algorithm>
#include <climits>
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

const int MAXN = 20;
int v[MAXN], R, E, dp[MAXN][MAXN];

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

template<typename T>
void setMax(T &a, T b)
{ if (b > a) a = b; }

int main()
{
  int cases = RI();
  REP1(cc, cases) {
    E = RI();
    R = RI();
    int N = RI();
    REP(i, N + 1)
      fill_n(dp[i], E + 1, INT_MIN / 2);
    dp[0][E] = 0;
    REP(i, N) {
      v[i] = RI();
      REP(j, E + 1)
        REP(k, j + 1)
          if (dp[i][j] >= 0) {
            int jj = min(j - k + R, E);
            setMax(dp[i+1][jj], dp[i][j] + v[i] * k);
          }
    }
    printf("Case #%d: %d\n", cc, *max_element(dp[N], dp[N] + E+1));
  }
}

