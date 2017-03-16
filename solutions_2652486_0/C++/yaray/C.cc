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
int R, N, M, K, a[10], b[10], c = 0;

int RI()
{
  int x;
  scanf("%d", &x);
  return x;
}

void push(int x)
{
  if (c < N) b[c++] = x;
}

int main()
{
  int cases = RI();
  REP1(cc, cases) {
    printf("Case #%d:\n", cc);
    R = RI();
    N = RI();
    M = RI();
    K = RI();
    REP(dd, R) {
      REP(i, K) a[i] = RI();
      c = 0;

      // 3, 5
      bool m3 = false, m9 = false, m27 = false;
      bool m5 = false, m25 = false, m125 = false;
      REP(i, K) {
        if (a[i] % 3 == 0) m3 = true;
        if (a[i] % 9 == 0) m9 = true;
        if (a[i] % 27 == 0) m27 = true;
        if (a[i] % 5 == 0) m5 = true;
        if (a[i] % 25 == 0) m25 = true;
        if (a[i] % 125 == 0) m125 = true;
      }

      if (m3) push(3);
      if (m9) push(3);
      if (m27) push(3);
      if (m5) push(5);
      if (m25) push(5);
      if (m125) push(5);

      // remove 3 5
      bool m4 = false;
      REP(i, K) {
        while (a[i] % 3 == 0) a[i] /= 3;
        while (a[i] % 5 == 0) a[i] /= 5;
        if (a[i] % 4 == 0) m4 = true;
      }
      if (m4) {
        push(4);
        push(2);
        push(2);
      } else {
        push(2);
        push(2);
        push(2);
      }
      REP(i, N) printf("%d", b[i]);
      puts("");
    }
  }
}
