// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/D-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/D-small.txt", "w", stdout);
  int tt, t, k, c, s, i;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> k >> c >> s;
    for (i = 1; i <= k; i++) {
      cout << i;
      if (i < k)
        cout << ' ';
      else
        cout << '\n';
    }
  }
  return 0;
}