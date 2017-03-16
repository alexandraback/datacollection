#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
#define SZ(a) ((int)a.size())
#define base 1000000007
#define MAXN 1005
using namespace std;

const double PI = 2.0 * acos (0.0);

typedef pair <int, int> PII;

template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

int full[MAXN], start[MAXN], finish[MAXN], inside[MAXN];
int ff[MAXN], ss[MAXN];
bool visit[MAXN], dd[MAXN];
string s[MAXN];
int n;

bool same(string s) {
    REP(i, s.length()) if (s[i] != s[0]) return false;
    return true;
}

void analyze(string s, int index) {
    if (same(s)) {
        full[s[0]]++;
        return;
    }
    int i = 0;
    ss[s[i]] = index;
    start[s[i]]++;
    while (s[i] == s[0]) i++;

    int j = s.length() - 1;
    ff[s[j]] = index;
    finish[s[j]]++;
    while (s[j] == s[s.length() - 1]) j--;
    for (int x = i; x <= j;) {
        char c = s[x];
        while (x <= j && s[x] == c) x++;
        inside[c]++;
    }
}

void init() {
    RESET(full, 0);
    RESET(finish, 0);
    RESET(start, 0);
    RESET(ss, 0);
    RESET(ff, 0);
    RESET(inside, 0);
    for (int i = 1; i <= n; i++) {
            analyze(s[i], i);
    }
}

void add(ll &res, int x) {
    ll s = 1;
    FOR(i, 1, x) s = (s * i) % base;
    res = res * s % base;
}

void solve() {
    FOR(c, 'a', 'z') {
        if (inside[c] > 1) {
            cout << 0 << endl;
            return;
        }
        //if (c == 'b') cout << "here" << endl;
        if (inside[c] == 1) {
            if (full[c] || start[c] || finish[c]) {
                cout << 0 << endl;
                return;
            }
        }
        //if (c == 'b') cout << "here" << endl;
        if (start[c] > 1 || finish[c] > 1) {
            cout << 0 << endl;
            return;
        }
        //if (c == 'b') cout << "here" << endl;
        //cout << ss[c] << ' ' << ff[c] << endl;
        if (start[c] == 1 && finish[c] == 1 && ss[c]== ff[c]) {
            cout << 0 << endl;
            return;
        }
        //if (c == 'b') cout << "here" << endl;
    }
    RESET(dd, false);
    RESET(visit, false);
/*    FOR(c, 1, 'z') if (!visit[c] && full[c] > 0) {
        char ch = c;
        while (1) {
            visit[ch] = true;
            add(res, full[ch]);
            int index = ff[ch];
            if (dd[index]) {
                cout << 0 << endl;
                return;
            }
            dd[index] = true;
            ch = s[index][0];
            if (finish[ch] == 0) break;
        }
        ch = c;
        while (1) {
            visit[ch] = true;
            if (ch != c) add(res, full[ch]);
            int index = ss[ch];
            if (dd[index]) {
                cout << 0 << endl;
                return;
            }
            dd[index] = true;
            ch = s[index][s[index].length() - 1];
            if (start[ch] == 0) break;
        }
        sl++;
    }
    FOR(i, 1, n) if (!dd[i]) {

    }
*/
    int sl = 0;
//    cout << "here" << endl;
    ll res = 1;
    FOR(i, 1, n) if (!same(s[i]) && !dd[i]) {
        char ch = s[i][0];
        while (1) {
            add(res, full[ch]);
            visit[ch] = true;
            if (finish[ch] == 0) break;
            int index = ff[ch];
            //cout << index << endl;
            if (dd[index]) {
                cout << 0 << endl;
                return;
            }
            dd[index] = true;
            ch = s[index][0];
        }
        ch = s[i][s[i].length() - 1];
        while (1) {
            add(res, full[ch]);
            visit[ch] = true;
            if (start[ch] == 0) break;
            int index = ss[ch];
            //cout << index << endl;
            if (dd[index]) {
                cout << 0 << endl;
                return;
            }
            dd[index] = true;
            ch = s[index][s[index].length() - 1];
        }
        sl++;
    }
    FOR(c, 'a', 'z') if (full[c] > 0 && !visit[c]) {
        add(res, full[c]);
        sl++;
    }
    add(res, sl);
    cout << res << endl;
}


int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    FOR(test, 1, _) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i, 1, n) cin >> s[i];
        init();
        solve();
    }
    return 0;
}
