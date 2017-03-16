#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>

bool fld[12][12][12];

int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  freopen("inp", "r", stdin);
  freopen("outp", "w", stdout);
  int t; cin >> t;
  for (int ii = 0; ii < t; ii++) {
    lint j, p, s, k;
    cin >> j >> p >> s >> k;
    memset(fld, 0, sizeof fld);
    int ans = 0;
    for (int i1 = 0; i1 < j; i1++)
      for (int i2 = 0; i2 < min(k, p); i2++)
        for (int i3 = 0; i3 < min(k, s); i3++) {
            fld[i1][(i1 + i2) % p][(i1 + i3) % s] = 1;
            ans++;
        }
    cout << "Case #" << ii+1 << ": " << ans << "\n";
    for (int i1 = 0; i1 < j; i1++)
      for (int i2 = 0; i2 < p; i2++)
        for (int i3 = 0; i3 < s; i3++) {
          if (fld[i1][i2][i3])
            cout << i1+1 << " " << i2+1 << " " << i3+1 << "\n";
        }
  }
}
