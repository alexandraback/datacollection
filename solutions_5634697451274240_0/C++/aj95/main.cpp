// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/B-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/B-small.txt", "w", stdout);
  int tt, t, i, j, k, n;
  string s;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> s;
    n = (int)s.size();
    i = n - 1;
    k = 0;
    while (i >= 0) {
      if (s[i] == '+')
        i--;
      else {
        for (j = 0; j < i; j++)
          s[j] = (s[j] == '+' ? '-' : '+');
        i--;
        k++;
      }
    }
    cout << k << '\n';
  }
  return 0;
}