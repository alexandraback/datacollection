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
    vector<ll> ret;
    if(k == s) {
      for(ll i=0; i<k; i++) {
        ll one = 1;
        ret.push_back(one + i * pow2(k, c-1));
      }
    }
    printf("Case #%d:",tc,ret);
    if(ret.size() > s || ret.size() == 0) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    for(int i=0; i<ret.size(); i++) {
      printf(" %lld", ret[i]);
    }
    cout << endl;
  }

  return 0;
}