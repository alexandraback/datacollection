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

bool solve(int x, int n, int m) {
  if (n > m) {
    swap(n, m);
  }
  if ((n * m) % x != 0) {
    return false;
  }
  if (n == 1) {
    return x <= 2;
  }
  if (n == 2) {
    return x <= 3;
  }
  if (n == 3) {
  }

  if (x >= 7) {
    return false;
  }
  if (x >= m + n) {
    return false;
  }
  if (x == m + n - 1) {
    return n == 1;
  }
  for (int w1 = 0; w1 + m <= x; ++w1) {
    for (int w2 = 0; w2 <= w1 && w1 + w2 + m <= x; ++w2) {
      assert(w1 + w2 + 1 < n);
    }
  }
  for (int z = 1; m + z < x; ++z) {
    bool ok = false;
    for (int col = 1; col < n - 1; ++col) {
      ok |= (col * n - z) % x == 0;
    }
    if (!ok) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x, n, m;
  assert(scanf("%d%d%d", &x, &n, &m) == 3);
  printf("%s\n", solve(x, n, m) ? "GABRIEL" : "RICHARD");
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

