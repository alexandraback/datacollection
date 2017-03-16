#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int b;
long long m;
int path[50][50];

void solve() {
  cin >> b >> m;
  memset(path, 0, sizeof(path));

  long long maxv = 1LL << (b-2);
  if (m > maxv) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  cout << "POSSIBLE" << endl;
  REP (i, b-1) REP (j, b-1) if (i < j) path[i][j] = 1;
  if (m == maxv) {
    REP (i, b-1) path[i][b-1] = 1;
  } else {
    FOR (i, 1, b-1) if (m & 1<<(i-1)) path[i][b-1] = 1;
  }

  REP (i, b) {
    REP (j, b) cout << path[i][j];
    cout << endl;
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
