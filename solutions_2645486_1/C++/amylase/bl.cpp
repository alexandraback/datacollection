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

    vector<li> mine(n, 0), maxe(n, e), v(n);
    priority_queue<pair<li, li> > q;
    rep(i, n) {
        cin >> v[i];
        q.push(make_pair(v[i], i));
    }

    li ans = 0;
    while (not q.empty()) {
        li pos = q.top().second;
        li value = q.top().first;
        q.pop();

        // cout << pos << " " << value << " " << maxe[pos] << " " << mine[pos] << endl;

        ans += (maxe[pos] - mine[pos]) * v[pos];

        li ne = mine[pos] + r;
        li npos = pos + 1;
        while (ne < e && npos < n) {
            maxe[npos] = min(maxe[npos], ne);
            ne += r;
            npos += 1;
        }

        ne = maxe[pos];
        npos = pos;
        while (ne > 0 && npos >= 0) {
            mine[npos] = max(mine[npos], ne);
            ne -= r;
            npos -= 1;
        }
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
