#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n+1)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 1000, M = 32; // M*M > N
int a[N], d[N+1][M+1], s[N+1];

int main()
{
  REP1(i, N)
    for (int j = min(i, M); j >= 0; j--)
      d[i][j] = (i+j)/(j+1);
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    REP(i, n)
      a[i] = ri();
    int m = *max_element(a, a+n);
    fill_n(s, m, 0);
    REP(i, n) {
      int x = 1;
      while (x*x < a[i]) x++;
      ROF(j, 0, m+1) {
        s[j] = max(s[j], a[i]);
        REP1(k, min(x, j))
          s[j] = min(s[j], max(s[j-k], d[a[i]][k]));
      }
    }
    ROF(i, 0, m)
      m = min(m, i+s[i]);
    printf("Case #%d: %d\n", cc, m);
  }
}
