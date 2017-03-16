#include <bits/stdtr1c++.h>
using namespace std;

typedef long long ll;

bool s[51][51];

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    memset(s, 0, sizeof s);
    cout << "Case #" << T << ": ";
    ll b, m; cin >> b >> m;
    if ((1LL<<(b-2)) < m) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << "POSSIBLE\n";
    ll mm = (1LL<<(b-2));
    for (int i = b-1; i; i--) {
      for (int j = i+1; j < b; j++)
        s[i][j] = true;
      if (mm-(1LL<<(i-2)) >= m)
        mm -= (1LL<<(i-2));
      else
        s[i][b] = true;
    }
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= b; j++)
        cout << s[i][j];
      cout << "\n";
    }
  }
  return 0;
}
