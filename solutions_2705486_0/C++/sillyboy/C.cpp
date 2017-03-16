//written by HTTPs - Ho Sy Viet Anh
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <fstream>
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
#define PII pair <int, int>

using namespace std;

#define maxn 1000011

string a[maxn], b[maxn], s;
int n, len;
vector<int> s0[255], s1[255];
int f[5000][10];

void init() {
    int maxx = 0;
    FOR(i, 1, n) {
        s0[a[i][0]].PB(i);
        if (a[i].length() > 1) s1[a[i][1]].PB(i);
        else s1[' '].PB(i);
        maxx = max(maxx, (int)a[i].length());
    }
}

int min(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    if (a < b) return a;
    return b;
}

void update(int i, int j, int k) {
    string t = a[k];
    if (len - i < t.length()) return;
    string sb = s.substr(i + 1, t.length());

    int last = -j, cnt = 0;
    REP(x, t.length()) {
        if (sb[x] != t[x]) {
            if (x  + 1 - last < 5) return;
            last = x + 1;
            cnt++;
        }
    }
    int id1 = i + t.length(), id2 = min((int)t.length() - last, 4);
    f[id1][id2] = min(f[id1][id2], f[i][j] + cnt);
}

void update2(int i, int j, int k) {
    string t = a[k];
    if (len - i < t.length()) return;
    string sb = s.substr(i + 1, t.length());

    int last = -j, cnt = 0;
    REP(x, t.length()) {
        if (sb[x] != t[x]) {
            if (x  + 1 - last < 5) return;
            last = x + 1;
            cnt++;
        }
    }
    int id1 = i + t.length(), id2 = min((int)t.length() - last, 4);

    f[id1][id2] = min(f[id1][id2], f[i][j] + cnt);
}

void process() {
    len = s.length();
    s = " " + s;
    RESET(f, -1);
    f[0][4] = 0;
    FOR(i, 0, len - 1) {
        FOR(j, 0, 5) if (f[i][j] >= 0) {
            int c = s[i + 1];
            REP(k, s0[c].size())
                update(i, j, s0[c][k]);
            if (i < len - 1) {
                c = s[i + 2];
                REP(k, s1[c].size())
                    update2(i, j, s1[c][k]);
            }
            REP(k, s1[' '].size())
                update2(i, j, s1[' '][k]);
        }
    }
    int res = -1;
    FOR(i, 0, 4) res = min(res, f[len][i]);
    cout << res << endl;
}

int main () {
    ifstream dict;
    dict.open("garbled_email_dictionary.txt");
    while (dict >> a[++n]);
    n--;
    init();
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> s;
        cout << "Case #" << test << ": ";
        process();
    }
    return 0;
}
