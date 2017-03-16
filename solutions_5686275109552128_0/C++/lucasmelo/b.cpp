#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define infl 0x3f3f3f3f3f3f3f3fLL

#define MAXN 1001
int n;

ll p[MAXN];

ll cost(ll x) {
  ll ans = x;
  for(int i=0; i<n; i++) {
    if (p[i] - x > 0) {
      ans += (p[i] - x + x - 1) / x;
    }
  }
  return ans;
}

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {

    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> p[i];
    }

    ll ans = infl;
    for(int j=1; j<=MAXN; j++) {
      ll v = j;
      for(int i=0; i<n; i++) {
        if (p[i] - j > 0) {
          v += ( p[i] - j + j - 1 ) / j;
        }
      }
      ans = min(ans, v);
    }

    printf("Case #%d: %lld\n", cn, ans);
  }
  return 0;
}
