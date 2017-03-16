// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int f[1111];
vector<int> v, w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/C-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/C-smalltxt", "w", stdout);
  int t, tt, i, j, n, m, a, x, y;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> f[i];
      --f[i];
    }
    a = 0;
    for (i = 0; i < (1 << n); i++) {
      if (__builtin_popcount(i) < a)
        continue;
      v.clear();
      w.clear();
      for (j = 0; j < n; j++) {
        if (i & (1 << j)) {
          v.push_back(j);
          w.push_back(f[j]);
        }
      }
      m = (int)v.size();
      for (j = 0; j < m; j++)
        if (find(v.begin(), v.end(), w[j]) == v.end())
          break;
      if (j == m) {
        do {
          for (j = 0; j < m; j++) {
            x = (j == 0) ? v[m - 1] : v[j - 1];
            y = (j + 1 == m) ? v[0] : v[j + 1];
            if (f[v[j]] == x || f[v[j]] == y)
              continue;
            else
              break;
          }
          if (j == m) {
            a = m;
            break;
          }
        } while (next_permutation(v.begin(), v.end()));
      }
    }
    cout << a << '\n';
  }
  return 0;
}