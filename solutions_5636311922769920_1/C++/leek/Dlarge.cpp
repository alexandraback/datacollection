#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll pow2(ll b, ll p ) {
  if(p== 0) return 1;
  ll hf = pow2(b, p/2);
  ll ret = hf * hf;
  if(p % 2) ret *= b;
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    ll k, c, s;
    cin >> k >> c >> s;
    printf("Case #%d:",tc);
    if (c == 1) {
      if(k <= s) {
        for(int i=1; i<=k; i++)
          printf(" %d", i);
      } else {
        printf(" IMPOSSIBLE");
      }
    } else {
      if((k+1)/2 <= s) {
        ll xx = pow2(k, c-1);
        for(ll i = 0; i < k ; i+=2) {
          printf(" %lld", min(xx*k, 1 + xx * i + i + 1)); 
        }
      } else {
        printf(" IMPOSSIBLE");
      }
    }
    printf("\n");
  }

  return 0;
}