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

ll findDiv(int d, const vector <int> & bits) {
  for (ll i = 2; i * i <= int(1e6); ++i) {
    ll rem = 0;
    for (int j = 0; j < int(bits.size()); ++j) {
      rem = (rem * d + bits[j]) % i;
    }
    if (rem == 0) {
      return i;
    }
  }
  return -1;
}

void solve() {
  printf("\n");
  int n, J;
  scanf("%d%d", &n, &J);
  for (ll i = (1LL << (n - 1)) + 1; J > 0 && i < (1LL << n); i += 2) {
    dbg("i %lld\n", i);
    vector <int> bits;
    bits.reserve(n);
    for (ll j = i; j; j /= 2) {
      bits.push_back(j & 1);
    }
    assert(int(bits.size()) == n);
    reverse(bits.begin(), bits.end());
    for (int j = 0; j < n; ++j) {
      dbg("%d", bits[j]);
    }
    dbg("\n");

    bool ok = true;
    vector <ll> divs(11);
    for (int d = 2; d <= 10; ++d) {
      divs[d] = findDiv(d, bits);
      if (divs[d] == -1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      for (int j = 0; j < int(bits.size()); ++j) {
        printf("%d", bits[j]);
      }
      for (int d = 2; d <= 10; ++d) {
        printf(" %lld", divs[d]);
      }
      printf("\n");
      --J;
    }
  }
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

