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
  int n;
  scanf("%d", &n);
  int mask = 0;
  ll curN = 0;
  int no_changes = 0;
  while (mask != (1 << 10) - 1) {
    int old_mask = mask;
    curN += n;
    for (ll i = curN; i; i /= 10) {
      mask |= (1 << (i % 10));
    }
    dbg("curN %lld, mask %d\n", curN, mask);
    if (mask == old_mask) {
      no_changes++;
      if (no_changes >= 10000) {
        printf("INSOMNIA\n");
        return;
      }
    } else {
      no_changes = 0;
    }
  }
  printf("%lld\n", curN);
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
    printf("Case #%d: ", ii);
    solve();
    fflush(stdout);
  }

  return 0;
}

