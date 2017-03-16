#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long long ll;

map<pair<ll,pair<ll,ll>>,ll> ma;

ll solve(ll a, ll b, ll k) {
  if (min(a,b) <= k) return a * b;
  if (a == 0 || b == 0 || k == 0) return 0;
  if (a == 1) return b;
  if (b == 1) return a;
  if (ma.count(make_pair(a,make_pair(b,k)))) return ma[make_pair(a,make_pair(b,k))];
  ll res = 0;
  ll a1 = (a+1)/2, a2 = a/2;
  ll b1 = (b+1)/2, b2 = b/2;
  ll k1 = (k+1)/2, k2 = k/2;
  res += solve(a1, b1, k1);
  res += solve(a1, b2, k1);
  res += solve(a2, b1, k1);
  if (k % 2 == 0) res += solve(a2, b2, k2);
  else res += solve(a2, b2, k1-1);
  //cout << a << " " << b << " " << k << " " << res << endl;
  return ma[make_pair(a,make_pair(b,k))] = res;
}

int main() {
  int t;
  cin >> t;
  REP(cas,t) {
    ma.clear();
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = solve(a, b, c);
    printf("Case #%d: %lld\n", cas+1, res);
  }
  return 0;
}
