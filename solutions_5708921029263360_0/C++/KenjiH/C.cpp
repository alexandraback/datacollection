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

int x, y, z;
int k;
bool ng[10][10][10];
int xy[10][10];
int yz[10][10];
int zx[10][10];

bool check(const vector<int> &v) {
  int a = v[0];
  int b = v[1];
  int c = v[2];
  if (ng[a][b][c]) return false;
  return xy[a][b] > k || yz[b][c] > k || zx[c][a] > k;
}

int calc(int a, int b, int c) {
  vector<int> v = {a, b, c};

  set<vector<int> > s;
  REP (i, x) {
    v[0] = i;
    if (check(v))
      s.insert(v);
  }
  v[0] = a;
  REP (i, y) {
    v[1] = i;
    if (check(v))
      s.insert(v);
  }
  v[1] = b;
  REP (i, z) {
    v[2] = i;
    if (check(v))
      s.insert(v);
  }
  
  return s.size();
}

void solve() {
  cin >> x >> y >> z >> k;

  memset(ng, 0, sizeof(ng));
  memset(xy, 0, sizeof(xy));
  memset(yz, 0, sizeof(yz));
  memset(zx, 0, sizeof(zx));  

  REP (a, x) REP (b, y) REP (c, z) {
    xy[a][b]++;
    yz[b][c]++;
    zx[c][a]++;
  }
  
  while (true) {
    int ra, rb, rc;
    int score = 0;
    REP (a, x) REP (b, y) REP (c, z) {
      if (ng[a][b][c]) continue;
      int tmp = calc(a, b, c);
      if (tmp > score) {
        score = tmp;
        ra = a;
        rb = b;
        rc = c;
      }
    }
    if (score) {
      ng[ra][rb][rc] = true;
      --xy[ra][rb];
      --yz[rb][rc];
      --zx[rc][ra];
    } else {
      break;
    }
  }

  int ret = 0;
  REP (a, x) REP (b, y) REP (c, z) if (!ng[a][b][c]) ++ret;
  cout << ret << endl;
  REP (a, x) REP (b, y) REP (c, z) if (!ng[a][b][c]) cout << (a+1) << " " << (b+1) << " " << (c+1) << endl;
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
