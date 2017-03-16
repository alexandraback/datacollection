#include <bits/stdc++.h>

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
  int k, c, s;
  scanf("%d%d%d", &k, &c, &s);
  if (c * s < k) {
    printf("IMPOSSIBLE\n");
    return;
  }
  int cnt = 0;
  for (int i = 0; i < k; i += c) {
    ++cnt;
    assert(cnt <= s);
    ll pos = 0;
    for (int j = 0; j < c; ++j) {
      pos = pos * k + (i + j) % k;
    }
    printf(" %lld", pos + 1);
  }
  printf("\n");
}

int main()
{
#ifdef DBG1
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  assert(freopen("err.txt", "w", stderr));
#endif

  int tt;
  assert (scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    dbg("Case %d\n", ii);
    printf("Case #%d:", ii);
    solve();
    fflush(stdout);
  }

  return 0;
}

