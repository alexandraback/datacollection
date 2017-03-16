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

#define rep(i,to)       for(li i=0;i<((li)to);++i)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

template <class T> inline void minu(T& x, T y) { x = min(x, y); }
template <class T> inline void maxu(T& x, T y) { x = max(x, y); }

inline li bit(li n){ return 1LL<<n; }
template <class T> ostream& operator<<(ostream& os, vector<T> x){
    foreach(it, x) os << *it << ' ';
    return os;
}

li dx[8] = {1, -1, 0,  0, -1, 1,  1, -1};
li dy[8] = {0,  0, 1, -1, -1, 1, -1,  1};

class Counter {
    vector<vector<bool> > f;
    li n, m;
    vector<vi> memo;
public:
    Counter(vector<vector<bool> >& _f): f(_f), n(f.size()), m(f[0].size()), memo(n, vi(m, 1)) {}
    void dfs(li i, li j) {
        if (f[i][j]) return;
        if (memo[i][j] == 0) return;
        memo[i][j] = 0;
        rep(d, 4) {
            li ni = i + dx[d];
            li nj = j + dy[d];
            if (ni < 0 || nj < 0) continue;
            if (ni >= n || nj >= m) continue;
            if (f[ni][nj]) continue;
            dfs(ni, nj);
        }
        return;
    }
    li ans() {
        li ret = 0;
        rep(i, n)  {
            dfs(i, 0);
            dfs(i, m-1);
        }
        rep(j, m) {
            dfs(0, j);
            dfs(n-1, j);
        }
        rep(i, n) rep(j, m) ret += memo[i][j];
        return ret;
    }

};

void solve(int caseNum) {
    li n, m, k;
    cin >> n >> m >> k;
    li ans = k;
    rep(mask, bit(n * m)) {
        li tans = __builtin_popcountll(mask);
        if (tans >= ans) continue;
        vector<vector<bool> > f(n, vector<bool>(m, false));
        rep(i, n) rep(j, m) {
            li pos = i * m + j;
            f[i][j] = (bool)(mask & bit(pos));
        }
        Counter cnter(f);
        if (cnter.ans() >= k) ans = min(ans, tans);

    }
    cout << "Case #" << caseNum << ": " << ans << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) solve(i + 1);
    return 0;
}
