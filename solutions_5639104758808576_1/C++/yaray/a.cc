#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n+1)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 1000;
int a[N+1];

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int n = ri();
    REP(i, n+1)
      scanf("%1d", &a[i]);
    REP(i, n+1) {
      int s = i, j;
      for (j = 0; j <= n; j++)
        if (j <= s)
          s += a[j];
        else
          break;
      if (j > n) {
        printf("Case #%d: %d\n", cc, i);
        break;
      }
    }
  }
}
