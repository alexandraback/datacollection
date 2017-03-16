#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

const int N = 20, M = 40;
int type[N], key[N+1][M+1], succ[1 << N], has[M];

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

int main()
{
  int cases = RI();
  REP1(cc, cases) {
    key[N][0] = RI();
    int n = RI();
    REP1(j, key[N][0])
      key[N][j] = RI() - 1;
    REP(i, n) {
      type[i] = RI() - 1;
      key[i][0] = RI();
      REP1(j, key[i][0])
        key[i][j] = RI() - 1;
    }

    fill_n(succ, 1 << n, -1);
    succ[(1 << n) - 1] = n;

    ROF(mask, 0, 1 << n) {
      fill_n(has, M, 0);
      REP1(j, key[N][0])
        has[key[N][j]]++;
      REP(i, n)
        if (mask & 1 << i) {
          REP1(j, key[i][0])
            has[key[i][j]]++;
          has[type[i]]--;
        }

      REP(i, M)
        if (has[i] < 0)
          goto L1;

      REP(i, n) {
        int mask2 = mask | 1 << i;
        if (mask2 != mask && has[type[i]] && succ[mask2] != -1) {
          succ[mask] = i;
          break;
        }
      }

L1:;
    }

    printf("Case #%d:", cc);
    if (-1 == succ[0])
      puts(" IMPOSSIBLE");
    else {
      for (int mask = 0; mask < (1 << n) - 1; mask |= 1 << succ[mask])
        printf(" %d", succ[mask] + 1);
      puts("");
    }
  }
}
