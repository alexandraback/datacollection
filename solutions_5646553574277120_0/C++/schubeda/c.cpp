#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <tuple>
#include <numeric>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

ll binpow(ll x) {
  ll result = 1;
  for (ll i=0; i<x; ++i) result *= 2;
  return result;
}

int main() {

  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  scanf("%d", &T);

  for (int t=1; t<=T; ++t) {
    printf("Case #%d: ", t);
    ll C, D, V;
    cin >> C >> D >> V;
    vector<ll> Ex(D,0);
    for (ll i=0; i<D; ++i) cin >> Ex[i];
    ll result = 0;
    for (ll v=1; v<=V; ++v) {
      ll i;
      for (i=0; i<binpow(Ex.size()); ++i) {
        ll sum = 0;
        for (ll j=0; j<Ex.size(); ++j) sum += Ex[j]*((i/binpow(j))%2);
        if (sum==v) break;
      } 
      if (i==binpow(Ex.size())) {
        Ex.push_back(v);
        ++result;
      }
    }
    cout << result << endl;
  }
}
