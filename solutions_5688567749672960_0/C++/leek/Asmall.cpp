#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll inf = 1e15;
int T;
ll N;
map <ll, ll> dp;

ll rev(ll x) {
  ll ret = 0;
  while(x>0) {
    ret = ret*10 + x%10;
    x = x/10;
  }
  return ret;
}

ll solve(ll n) {
  if(dp.find(n) != dp.end()) return dp[n];
  ll ret = inf;
  if(n ==1) return 1;
  ll cand = rev(n);
  if(rev(cand) == n && rev(n) < n)
    ret = min(ret, solve(cand) +1);
  ret = min(ret, solve(n-1) + 1);
  dp[n] = ret;
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> N;

    ll ret = solve(N);
    printf("Case #%d: %Ld\n",tc,ret);

  }

  return 0;
}