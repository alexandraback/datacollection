#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int N, J;
    scanf("%d %d", &N, &J);

    printf("Case #%d:\n", tp);
    
    for (int s = 0; s < (1<<(N-2)) && J > 0; ++s) {
      static int d[32];
      d[0] = d[N-1] = 1;
      REP(i, N-2) d[i+1] = (s>>i) & 1;
      
      bool ok = true;
      static int pr[11];
      FOR(b, 2, 11) {
        int div = -1;
        for (int x: {2, 3, 5, 7, 11}) {
          int rem = 0;
          REP(i, N) rem = (rem*b + d[i]) % x;
          if (rem == 0) { div = x; break; }
        }
        if (div == -1) { ok = false; break; }
        pr[b] = div;
      }

      if (ok) {
        J--;
        REP(i, N) putchar(d[i] + '0');
        FOR(b, 2, 11) printf(" %d", pr[b]);
        printf("\n");
      }
    }

  }
  return 0;
}
