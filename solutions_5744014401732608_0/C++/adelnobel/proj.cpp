#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, char> pc;
typedef long long ll;

const int N = 55;
bool mat[N][N];
ll n, m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> n >> m;
    cout << "Case #" << t << ": ";
    memset(mat, false, sizeof mat);
    if (m > (1LL << (n - 2))) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << "POSSIBLE" << endl;
      for (int i = 2; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
          mat[i][j] = true;
        }
      }
      if ((m & (m - 1)) == 0) {
        mat[1][n] = true;
        m--;
      }
      for (int i = 0; i < 60; i++) {
        if (m & (1LL << i)) {
          mat[1][n - i - 1] = true;
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          cout << mat[i][j];
        }
        cout << endl;
      }
    }

  }

  return 0;
}
