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

int a[100][100];

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    int h,w;
    cin >> h >> w;
    REP(i,h)REP(j,w) cin >> a[i][j];
    bool ans = 1;
    REP(i,h) {
      REP(j,w) {
        bool ok = 0;
        bool tmp = 1;
        REP(k,h) {
          if (a[k][j] > a[i][j]) tmp = 0;
        }
        ok |= tmp;
        tmp = 1;
        REP(k,w) {
          if (a[i][k] > a[i][j]) tmp = 0;
        }
        ok |= tmp;
        ans &= ok;
      }
    }
    printf("Case #%d: ", cs+1);
    cout << (ans?"YES":"NO") << endl;
  }
}
