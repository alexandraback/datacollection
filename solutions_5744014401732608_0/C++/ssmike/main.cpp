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

const int MAXN = 60;

int edg[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  freopen("inp", "r", stdin);
  freopen("outp", "w", stdout);
  int t; cin >> t;
  for (int ii = 0; ii < t; ii++) {
    lint b, m;
    cin >> b >> m;
    cout << "Case #" << ii+1 << ": ";
    memset(edg, 0, sizeof edg);
    if ((1 << (b - 2)) >= m) {
      if ((1 << (b - 2)) == m)
        for (int i = 0; i < b - 1; i++)
          edg[i][b - 1] = 1;
      cout << "POSSIBLE\n";
      for (int i = 0; i < b - 1; i++) {
        for (int j = i + 1; j < b - 1; j++)
          edg[i][j] = 1;
      }
      
      for (int i = 1; i < b - 1; i++) {
        if (((m >> (i - 1))&1) != 0)
          edg[i][b - 1] = 1;
      }
      for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++)
          cout << edg[i][j];
        cout << "\n";
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
}
