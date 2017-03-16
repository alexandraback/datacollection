#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

char a[55][55];

bool solve(int n, int m, int k) {
  if (k == 1) {
    REP(i, n) REP(j, m) a[i][j] = '*';
    a[0][0] = 'c';
    return true;
  }
  if (n == 1) {
    REP(i, m) a[0][i] = (i < k) ? '.' : '*';
    a[0][0] = 'c';
    return true;
  }
  if (m == 1) {
    REP(i, n) a[i][0] = (i < k) ? '.' : '*';
    a[0][0] = 'c';
    return true;
  }
      
  for (int A = 2; A <= m; ++A)
    for (int B = 2; B <= n; ++B) {
      int lo = 2*A + 2*B - 4;
      int hi = A*B;

      if (lo <= k && k <= hi) {
        REP(i, n) REP(j, m) a[i][j] = '*';
        REP(j, A) a[0][j] = a[1][j] = '.';
        REP(i, B) a[i][0] = a[i][1] = '.';
        a[0][0] = 'c';
        k -= lo;
        for (int i = 2; i < B && k > 0; ++i)
          for (int j = 2; j < A && k > 0; ++j)
            a[i][j] = '.', k--;
        return true;
      }
    }
  return false;
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    printf("Case #%d:\n", tp);

    if (solve(n, m, n*m - k)) {
      REP(i, n) {
        a[i][m] = '\0';
        puts(a[i]);
      }
    } else
      puts("Impossible");

  }
  return 0;
}
