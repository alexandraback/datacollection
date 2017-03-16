#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;


void solve() {
  string s; cin >> s;
  int n = (int)s.size();

  int ans = s[n-1] != '+';
  for (int i = 1; i < n; ++i) {
    ans += s[i] != s[i-1];
  }

  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
