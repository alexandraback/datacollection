#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int TC, R, C, grid[110][110];

bool check() {
  FOR(r, 0, R) FOR(c, 0, C) {
    bool row = false, col = false;
    FOR(i, 0, R) if (grid[i][c] > grid[r][c]) row = true;
    FOR(i, 0, C) if (grid[r][i] > grid[r][c]) col = true;
    if (row && col) return false;
  }
  return true;
}

int main() {
  cin >> TC;
  FOR(cs, 1, TC+1) {
    cin >> R >> C;
    FOR(i, 0, R) FOR(j, 0, C) cin >> grid[i][j];
    cout << "Case #" << cs << ": ";
    if (check()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
	return 0;
}
