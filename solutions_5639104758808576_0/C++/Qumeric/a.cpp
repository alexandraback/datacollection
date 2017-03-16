#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int main() {
  freopen("a1.in", "r", stdin);
  freopen("a1.out", "w", stdout);
  cin >> t;
  for (int x = 1; x <= t; x++) {
    int cur = 0, ans = 0;
    int a; string b; cin >> a >> b;
    for (int i = 0; i <= a; i++) {
      if(i > cur) {
        ans += i-cur;
        cur += i-cur;
      }
      cur += b[i] - '0';
    }
    cout << "Case #" << x << ": " << ans << '\n';
  }
}
