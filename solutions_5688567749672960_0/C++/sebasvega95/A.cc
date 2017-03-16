#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
const ll MN = (ll)(1E6) + 10LL;
ll dp[MN];

ll f(ll k) {
  if (dp[k] != -1)
    return dp[k];

  //cout << "->" << k << endl;

  if (k == n)
    return 1;
  if (k > n)
    return (ll)(1E9);

  stringstream ss;
  ss << k;
  string s = ss.str();
  reverse(s.begin(), s.end());

  ll k2 = atol(s.c_str());

  //cout << ": " << k+1 << " " << k2 << endl;
  //getchar();

  if (k < 10 or k2 <= k)
    return dp[k] = 1 + f(k+1);
  else
    return dp[k] = 1 + min( f(k+1), f(k2) );
}

void solve() {
  cin >> n;
  memset(dp, -1, sizeof dp);
  printf( "%lld\n", f(1) );
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
