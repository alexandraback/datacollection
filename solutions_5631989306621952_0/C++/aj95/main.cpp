// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/A-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/A-small.txt", "w", stdout);
  int i, n, tc, tt;
  string s, t;
  cin >> tt;
  for (tc = 1; tc <= tt; tc++) {
    cout << "Case #" << tc << ": ";
    cin >> s;
    n = (int)s.size();
    t = "";
    for (i = 0; i < n; i++) {
      if (t.empty() || t[0] > s[i]) {
        t += s[i];
      } else {
        t = s[i] + t;
      }
    }
    cout << t << '\n';
  }
  return 0;
}