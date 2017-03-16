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

li r, n, m, k;
li p[12];
void solve_sub() {
    rep(i, k) cin >> p[i];

    vector<li> ans(n, 2), tmp(n, 2);
    double like = 0;

    while (true) {
        map<li, double> prob;
        rep(mask, bit(n)) {
            li prod = 1;
            rep(i, n) if (bit(i) & mask) prod *= tmp[i];
            prob[prod] += 1.0 / bit(n);
        }

        double tmplike = 1;
        rep(i, k) tmplike *= prob[p[i]];

        if (tmplike > like) {
            like = tmplike;
            ans = tmp;
        }
        
        // update
        li addpos = 0;
        for (; addpos < n; ++addpos) {
            if (tmp[addpos] < m) break;
            else tmp[addpos] = 2;
        }
        if (addpos == n) break;
        tmp[addpos] += 1;
    }

    rep(i, n) cout << ans[i];
    cout << endl;
    return;
}

void solve(int caseNum) {
    cout << "Case #" << caseNum << ":" << endl;
    cin >> r >> n >> m >> k;
    rep(i, r) solve_sub();
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) solve(i + 1);
    return 0;
}
