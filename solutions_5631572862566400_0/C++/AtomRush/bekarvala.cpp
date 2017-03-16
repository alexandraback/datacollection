#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef unsigned long long llu;

#define author ayushtomar
#define rf freopen("toms.in", "r", stdin)
#define wf freopen("out.txt", "w", stdout)
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int f[1111];
vector<int> v, w;

int main() {
  rf ; wf;
 // ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int t, tt, i, j, n, m, a, x, y;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> f[i];
      --f[i];
    }
      cout << "Case #" << t << ": ";

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
