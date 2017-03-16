#include <bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif // M_PI
#define endl "\n"
#define S struct
#define X first
#define Y second
#define V vector
#ifndef __linux__
#define LLD "%I64d"
#else
#define LLD "%ll""d"
#endif
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];
#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];
#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };
#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";
#define IT(a) a.begin(), a.end()
#define SQR(x) (x) * (x)
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl; cout.flush();
#define IFDEB(b, a) if (b) { cout << #a << " = " << (a) << endl; cout.flush(); }
using namespace std;
typedef long long LL;
#define int LL
typedef long double LD;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;
const int MOD = 1000000007;
void sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); }
S Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

int ok(int x, string s)
{
    FORR (i, int(s.size()) - 1, -1) {
        if (s[i] != '?' && s[i] - '0' != x % 10) {
            return 0;
        }
        x = x / 10;
    }
    if (x) {
        return 0;
    }
    return 1;
}

string x, y;
LL best;
LL res1, res2;
int flag;

LL toLL (const string &s)
{
    LL res1 = 0;
    FOR (i, 0, s.size()) {
        res1 *= 10;
        res1 += s[i] - '0';
    }
    return res1;
}

void check()
{
    LL a1 = toLL(x);
    LL a2 = toLL(y);
    if (flag) {
        swap(a1, a2);
    }
    if (abs(a1 - a2) < best) {
        best = abs(a1 - a2);
        res1 = a1;
        res2 = a2;
    } else if (abs(a1 - a2) > best) {
        return;
    } else {
        if (a1 < res1) {
            res1 = a1;
            res2 = a2;
        } else if (a1 == res1 && a2 < res2) {
            res2 = a2;
        }
    }
}

void solve(int pos, int eq)
{
    if (pos == x.size()) {
        check();
        return;
    }
    if (x[pos] == '?' && y[pos] == '?') {
        if (eq == 0) {
            auto t = x[pos];
            auto t2 = y[pos];
            x[pos] = '0';
            y[pos] = '0';
            solve(pos + 1, 0);
            x[pos] = '1';
            y[pos] = '0';
            solve(pos + 1, 1);
            x[pos] = t;
            y[pos] = t2;
        } else {
            auto t = x[pos];
            auto t2 = y[pos];
            x[pos] = '0';
            y[pos] = '9';
            solve(pos + 1, 1);
            x[pos] = t;
            y[pos] = t2;
        }
    } else if (y[pos] == '?') {
        if (eq == 0) {
            auto t2 = y[pos];
            y[pos] = x[pos];
            solve(pos + 1, 0);
            if (x[pos] != '0') {
                y[pos] = x[pos] - 1;
                solve(pos + 1, 1);
            }
            y[pos] = t2;
        } else {
            auto t2 = y[pos];
            y[pos] = '9';
            solve(pos + 1, 1);
            y[pos] = t2;
        }
    } else if (x[pos] == '?') {
        if (eq == 0) {
            auto t = x[pos];
            x[pos] = y[pos];
            solve(pos + 1, 0);
            if (y[pos] != '9') {
                x[pos] = y[pos] + 1;
                solve(pos + 1, 1);
            }
            x[pos] = t;
        } else {
            auto t = x[pos];
            x[pos] = '0';
            solve(pos + 1, 1);
            x[pos] = t;
        }
    } else {
        if (eq == 0) {
            if (y[pos] > x[pos]) {
                return;
            }
            if (y[pos] == x[pos]) {
                solve(pos + 1, 0);
            } else {
                solve(pos + 1, 1);
            }
        } else {
            solve(pos + 1, 1);
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    FOR (l, 0, t) {
        cerr << "CASE " << l + 1 << endl;
        string s, s2;
        cin >> s >> s2;
        string t1 = s;
        string t2 = s2;
        while (t1.size() < t2.size()) {
            t1 = '0' + t1;
        }
        while (t2.size() < t1.size()) {
            t2 = '0' + t2;
        }
        best = LLONG_MAX;
        x = t1;
        y = t2;
        flag = 0;
        solve(0, 0);
        x = t2;
        y = t1;
        flag = 1;
        solve(0, 0);
        string ans1 = to_string(res1);
        string ans2 = to_string(res2);
        while (ans1.size() < s.size()) {
            ans1 = '0' + ans1;
        }
        while (ans2.size() < s2.size()) {
            ans2 = '0' + ans2;
        }
        cout << "Case #" << l + 1 << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
