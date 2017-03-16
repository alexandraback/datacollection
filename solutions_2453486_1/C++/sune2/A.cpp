#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

char ba[4][4];

int check(int *cnt) {
  if (cnt[0] == 4 || cnt[0] == 3 && cnt[2] == 1) return 0;
  if (cnt[1] == 4 || cnt[1] == 3 && cnt[2] == 1) return 1;
  return -1;
}

int solve() {
  string s = "XOT.";
  REP(i,4) REP(j,4) cin >> ba[i][j];
  REP(y,4) {
    int cnt[4] = {};
    REP(x,4) cnt[s.find(ba[y][x])]++;
    int tmp = check(cnt);
    if (tmp >= 0) return tmp;
  }
  REP(x,4) {
    int cnt[4] = {};
    REP(y,4) cnt[s.find(ba[y][x])]++;
    int tmp = check(cnt);
    if (tmp >= 0) return tmp;
  }
  {
    int cnt[4] = {};
    REP(x,4) {
      cnt[s.find(ba[x][x])]++;
    }
    int tmp = check(cnt);
    if (tmp >= 0) return tmp;
  }
  {
    int cnt[4] = {};
    REP(x,4) {
      cnt[s.find(ba[3-x][x])]++;
    }
    int tmp = check(cnt);
    if (tmp >= 0) return tmp;
  }
  bool f = 0;
  REP(i,4)REP(j,4)if (ba[i][j] == '.') f = 1;
  if (f) return 3;
  return 2;
}

int main() {
  string ans[] = {"X won", "O won", "Draw", "Game has not completed"};
  int T;
  cin >> T;
  REP(cs,T) {
    printf("Case #%d: ", cs+1);
    cout << ans[solve()] << endl;
  }
}
