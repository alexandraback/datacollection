#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

ll toInt(string s) {
    char b[25];
    sprintf(b, "%s", s.c_str());
    ll r;
    sscanf(b, "%lld", &r);
    return r;
}
ll mpow(ll x, ll p) {
    ll res = 1;
    forn(i, p) {
        res *= x;
    }
    return res;
}
string toString(ll x) {
    char b[25];
    sprintf(b, "%lld", x);
    string s = b;
    return s;
}
string toString(ll x, int n) {
    string s = toString(x);
    while (s.length() < n) {
        s = '0' + s;
    }
    return s;
}
bool suf(ll x, string t) {
    if (x < 0)
        return false;
    string s = toString(x);
    while (s.length() < t.length()) {
        s = '0' + s;
    }
    if (s.length() != t.length())
        return false;
    forn(i, s.length()) {
        if (t[i] == '?')
            continue;
        if (s[i] != t[i])
            return false;
    }
    return true;
}
struct ans {
    ll s, t;
    bool operator < (const ans & o) const {
        ll s1 = (s);
        ll s2 = (o.s);
        ll t1 = (t);
        ll t2 = (o.t);
        if (abs(s1 - t1) != abs(s2 - t2)) {
            return (abs(s1 - t1) < abs(s2 - t2));
        }
        if (s1 != s2)
            return s1 < s2;
        return t1 < t2;
    }
};


void rec(int st, string s, vector<string> & v) {
    if (st == s.length()) {
        v.pb(s);
        return;
    }
    if (s[st] == '?') {
        forn(i, 10) {
            s[st] = '0' + i;
            rec(st + 1, s, v);
        }
    } else {
        rec(st + 1, s, v);
    }
}
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    vector<string> ss, tt;
    rec(0, s, ss);
    rec(0, t, tt);
    vector<ans> a;
    for (auto i : ss) {
        for (auto j : tt) {
            a.push_back({toInt(i), toInt(j)});
        }
    }
    ans c = a[0];
    for (auto i : a) {
        if (i < c)
            c = i;
    }
    cout << toString(c.s, n) << ' ' << toString(c.t, n) << '\n';

}
int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int T;
    cin >> T;
    forn(test, T) {
        printf("Case #%d: ", test + 1);
        solve();
    }
    
    return 0;
}

