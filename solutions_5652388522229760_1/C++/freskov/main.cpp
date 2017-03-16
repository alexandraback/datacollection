#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;


void solve() {
  int n; cin >> n;

  if (n == 0) {
    cout << "INSOMNIA" << endl;
    return;
  }

  vector<bool> seen(10, false);
  int cnt = 0;
  ll x = n;

  for ( ; ; x += n) {
    ll y = x;
    while (y) {
      cnt += !seen[y%10];
      seen[y%10] = true;
      y /= 10;
    }
    if (cnt == 10 || x < 0) break;
  }

  if (cnt < 10) cout << "INSOMNIA" << endl;
  else cout << x << endl;

}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
