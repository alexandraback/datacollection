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
  char s[1010];
  assert(scanf("%d %s", &n, s) == 2);
  assert((int)strlen(s) == n + 1);
  int res = 0, stood_up = 0;
  for (int i = 0; i <= n; ++i) {
    if (s[i] != '0') {
      if (stood_up < i) {
        res += i - stood_up;
        stood_up = i;
      }
      stood_up += s[i] - '0';
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

