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
  int c, n, v;
  assert(scanf("%d%d%d", &c, &n, &v) == 3);
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    assert(scanf("%d", &a[i]) == 1);
  }
  sort(a.begin(), a.end());

  int res = 0;
  int cur = 0;
  ll can = 0;
  while (can < v) {
    if (cur < n && a[cur] <= can + 1) {
      can += ll(a[cur]) * c;
      ++cur;
    } else {
      res++;
      ll newA = can + 1;
      can += newA * c;
    }
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

