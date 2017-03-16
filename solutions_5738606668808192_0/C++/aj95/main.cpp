// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Documents/cmd/h.txt", "r", stdin);
  freopen("/Users/Ayur/Documents/cmd/out.txt", "w", stdout);
  int n=16, i, j=50, k;
  cout << "Case #1:\n";
  string s, x;
  while (k < j) {
    cin >> s;
    if ((int)s.size() == n) {
      cout << s << ' ';
      for (i = 0; i < 9; i++) {
        cin >> x;
        cout << x;
        if (i < 8)
          cout << ' ';
        else
          cout << '\n';
      }
      k++;
    } else {
      for (i = 0; i < 9; i++)
        cin >> x;
    }
  }
  return 0;
}