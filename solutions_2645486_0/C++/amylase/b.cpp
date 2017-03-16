#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <complex>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long       li;
typedef vector<li>      vi;
typedef complex<double> pt;
typedef pair<pt, pt>    line;
typedef pair<li, li>    pi;
typedef vector<string>  vs;

#define rep(i,to)       for(li i=0;i<((li)to);i++)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

inline li bit(li n){ return 1LL<<n; }
template <class T> ostream& operator<<(ostream& os, vector<T> x){
  foreach(it, x) os << *it << ' ';
  return os;
}
template <class T> inline void dbg(T x){
  // return;
  cerr << x << endl; 
}

li vx[8] = {1, -1, 0,  0, -1, 1,  1, -1};
li vy[8] = {0,  0, 1, -1, -1, 1, -1,  1};

void solve(int caseNum) {
    li e, r, n;
    cin >> e >> r >> n;
    r = min(e, r);

    vector<li> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<li> > dp(n+1, vector<li>(e+1, 0));
    rep(i, n) {
        rep(j, e+1) {
            rep(use, j+1) {
                li newe = min(e, j - use + r);
                dp[i+1][newe] = max(dp[i+1][newe], dp[i][j] + use * v[i]);
            }
        }
    }

    li ans = 0;
    rep(i, e+1) ans = max(ans, dp[n][i]);
    cout << "Case #" << caseNum << ": " << ans << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) solve(i + 1);
    return 0;
}
