#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int n;
ll pow2(ll b, ll p ) {
  if(p== 0) return 1;
  ll hf = pow2(b, p/2);
  ll ret = hf * hf;
  if(p % 2) ret *= b;
  return ret;

}
string toString(ll x) {
  string ret = "";
  while( x > 0) {
    if ( x % 2 ) ret += '1';
    else ret += '0';
    x = x /2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}


vector<ll > okay(ll x) {
  vector<ll> ret;
  for(ll b =2 ;b<=10; b++) {
    ll y1 = 0;
    ll y2 = 0;

    ll xx = x;
    ll a = 1;
    while( xx >= (1 << (n/2))) {
      if(xx %2) y1 += a;
      a *= b;
      xx /=2;
    }
    a = 1;
    while( xx > 0) {
      if(xx %2) y2 += a;
      a *= b;
      xx /=2;
    }

    bool found = false;
    for(ll k = 2; k * k <= 100000000 ; k++) {
      ll m1 = y1 % k;
      ll m2 = y2 % k;
      ll m3 = pow2(b, n/2 )% k;
      if((( (m2 * m3) + m1) % k) == 0) {
        ret.push_back(k);
        found = true;
        break;
      }
    }
    if(!found) return ret;
  }
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    printf("Case #%d:\n",tc);
    int j;
    cin >> n >> j;
    ll one = 1;
    ll x = one << (n-1);
    x ++;
    while ( j >0 ) {
      if(x%2 ==0) {
        x ++;
        continue;
      }
      vector<ll> r = okay(x);
      if(r.size() == 9) {
        cout << toString(x);
        for(int i =0; i<r.size(); i++) {
          cout << ' ' << r[i];
        }
        cout << endl;
        j --;
      }
      x++;
    }

  }

  return 0;
}