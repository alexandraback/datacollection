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

const li mod = 1e9 + 7;

string normal(string& s) {
    string ret;
    char last = '@';
    foreach(c, s) if (*c != last) {
        ret.push_back(*c);
        last = *c;
    }
    return ret;
}

void solve(int caseNum) {
    li n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vi o;
    rep(i, n) o.push_back(i);
    rep(i, n) s[i] = normal(s[i]);
    li ans = 0;
    do {
        string st;
        rep(i, n) st += s[o[i]];
        set<char> used;
        char last = '@';
        bool ok = true;
        foreach(c, st) {
            if (used.find(*c) != used.end() && last != *c) {
                ok = false;
                break;
            }
            used.insert(*c);
            last = *c;
        }
        if (ok) ans += 1;
    } while (next_permutation(all(o)));
    ans %= mod;
    cout << "Case #" << caseNum << ": " << ans << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) solve(i + 1);
    return 0;
}
