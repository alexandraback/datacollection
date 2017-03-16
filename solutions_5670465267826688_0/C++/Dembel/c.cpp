#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int fromChar(char ch) {
  assert('i' <= ch && ch <= 'k');
  return ch - 'i' + 2;
}

const int I = fromChar('i');
const int J = fromChar('j');
const int K = fromChar('k');

int mult(int a, int b) {
  const static int matrix[4][4] =
    {
      {1, I, J, K},
      {I, -1, K, -J},
      {J, -K, -1, I},
      {K, J, -I, -1}
    };
  int sign = 1;
  if (a < 0) {
    sign *= -1;
    a *= -1;
  }
  if (b < 0) {
    sign *= -1;
    b *= -1;
  }
  assert(1 <= a && a <= 4 && 1 <= b && b <= 4);
  return sign * matrix[a - 1][b - 1];
}

bool solve(int x, int n, const char * s) {
  vector <int> pref(x * n + 1), suff(x * n + 1);
  pref[0] = 1;
  for (int i = 0; i < n * x; ++i) {
    pref[i + 1] = mult(pref[i], fromChar(s[i % n]));
  }
  suff[0] = 1;
  for (int i = 0; i < n * x; ++i) {
    suff[i + 1] = mult(fromChar(s[n - 1 - i % n]), suff[i]);
  }

  bool ok0 = (pref[n * x] == mult(I, mult(J, K)));
  int ok1 = -1, ok2 = -1;
  for (int i = 0; i <= n * x; ++i) {
    if (pref[i] == I && ok1 == -1) {
      ok1 = i;
    }
    if (suff[i] == K && ok2 == -1) {
      ok2 = i;
    }
  }
  return ok0 && ok1 != -1 && ok2 != -1 && (ok1 + ok2 <= n * x);
}

void solve() {
  int n;
  ll x;
  static char s[10010];
  assert(scanf("%d%lld %s", &n, &x, s) == 3);
  assert((int)strlen(s) == n);
  if (x > 8) {
    x = 8 + x % 4;
  }
  printf("%s\n", solve((int)x, n, s) ? "YES" : "NO");
}

int main()
{
  int tt;
  assert(scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }

  return 0;
}

