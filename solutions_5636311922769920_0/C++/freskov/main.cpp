#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;


void solve() {
  int k, c, s; cin >> k >> c >> s;
  ll total = 1;
  for (int i = 0; i < c; ++i) total *= k;

  if (k == 1) {
    cout << 1 << endl;
    return;
  }
  if (c * s < k) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<ll> ans;
  ll x = 0;
  for (int i = 0, pos = 0; i < s && pos < k; ++i) {
    x = 0;
    for (int j = 0; j < c; ++j, ++pos) {
      if (pos == k) x = x*k;
      else x = x*k + pos;
    }
    ans.push_back(x+1);
  }

  for (auto pos : ans) cout << pos << " ";
  cout << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

