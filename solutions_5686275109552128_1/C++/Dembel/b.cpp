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

void solve() {
  int n;
  assert(scanf("%d", &n) == 1);
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    assert(scanf("%d", &a[i]) == 1);
  }
  int res = 10000;
  for (int t = 1; t <= 1000; ++t) {
    int cur = t;
    for (int i = 0; i < n; ++i) {
      cur += (a[i] - 1) / t;
    }
    res = min(res, cur);
  }
  printf("%d\n", res);
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

