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
bool suf(string s, string t) {
    if (s.length() != t.length())
        return false;
    forn(i, s.length()) {
        if (s[i] < '0' || s[i] > '9')
            return false;
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

void app(string & s, string & t, bool fgr) {
    int n = s.length();
    forn(i, n) {
        if (s[i] == '?') {
            if (fgr)
                s[i] = '0';
            else
                s[i] = '9';
        }
        if (t[i] == '?') {
            if (fgr)
                t[i] = '9';
            else
                t[i] = '0';
        }
    }
}
void inc(string & s) {
    int n = s.length();
    ll x = toInt(s);
    x++;
    s = toString(x, n);
}
void dec(string & s) {
    int n = s.length();
    ll x = toInt(s);
    x--;
    s = toString(x, n);
}

void solve() {
    string s, t;
    cin >> s >> t;
    string ss = s, tt = t;
    int n = s.length();
    bool fgr = false, fset = false;
    int fpos = -1;
    forn(i, n) {
        if (!fset) {
            if (s[i] == '?' && t[i] == '?') {
                s[i] = t[i] = '0';
            } else if (s[i] == '?') {
                s[i] = t[i];
            } else if (t[i] == '?') {
                t[i] = s[i];
            } else if (s[i] != t[i]) {
                fpos = i;
                fset = true;
                fgr = s[i] > t[i];
                break;
            }
        }
    }
    ans a;

    if (fpos >= 0) {
        string spref = s.substr(0, fpos);
        string tpref = t.substr(0, fpos);
        string ssuf = s.substr(fpos);
        string tsuf = t.substr(fpos);
        string s2 = ssuf, t2 = tsuf;
        app(s2, t2, fgr);
        s2 = spref + s2, t2 = tpref + t2;
        a = {toInt(s2), toInt(t2)};
        assert(suf(s2, ss));
        assert(suf(t2, tt));

        if (fpos > 0) {
            string ns = spref, nt = tpref;
            if (a.s < a.t) {
                inc(ns);
                dec(nt);
            } else {
                inc(nt);
                dec(ns);
            }
            app(ssuf, tsuf, !fgr);

            if (suf(ns + ssuf, ss)) {
                a = min(a, ans({toInt(ns + ssuf), toInt(tpref + tsuf)}));
            }
            if (suf(nt + tsuf, tt)) {
                a = min(a, ans({toInt(spref + ssuf), toInt(nt + tsuf)}));
            }
        }
    } else {
        a = {toInt(s), toInt(t)};
        assert(suf(s, ss));
        assert(suf(t, tt));
    }
    cout << toString(a.s, n) << ' ' << toString(a.t, n) << '\n';

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

