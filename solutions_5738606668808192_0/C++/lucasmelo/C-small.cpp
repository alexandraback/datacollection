#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef DEBUG
#include "/Users/lucasmelo/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; debug,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

ll n, j;

ll num_len(ll x) {
  ll ans = 0;
  while (x > 0) {
    ++ ans;
    x /= 2;
  }
  return ans;
}

void print_binary(ll x, ll l) {
  for(ll k=0; k<l; k++) {
    if (x & (1ll << (l-k-1))) {
      printf("1");
    } else {
      printf("0");
    }
  }
}

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    printf("Case #%d:\n", cn);
    cin >> n >> j;

    for(ll i=0; i<j; i++) {
      ll a = 2*i+3;
      ll al = num_len(a);

      print_binary(a, al);
      for(ll k=0; k< n - 2*al; k++) {
        printf("0");
      }
      print_binary(a, al);

      for(ll k=2; k<=10; k++) {
        ll d = 0;
        ll b = 1;
        for(ll m=0; m<al; m++) {
          if (a & (1ll << m)) {
            d += b;
          }
          b *= k;
        }
        printf(" %lld", d);
      }
      printf("\n");
    }
  }
  return 0;
}
