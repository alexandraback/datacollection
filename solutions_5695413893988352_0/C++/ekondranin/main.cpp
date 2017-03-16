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

int main()
{
    int t;
    cin >> t;
    FOR (l, 0, t) {
        cerr << "CASE " << l + 1 << endl;
        string s, s2;
        cin >> s >> s2;
        int ans = INT_MAX;
        int ans1, ans2;
        FOR (i, 0, 1000) {
            FOR (j, 0, 1000) {
                if (ok(i, s) && ok(j, s2) && abs(i - j) < ans) {
                    ans = abs(i - j);
                    ans1 = i;
                    ans2 = j;
                }
            }
        }
        string res1 = to_string(ans1);
        string res2 = to_string(ans2);
        while (res1.size() < s.size()) {
            res1 = '0' + res1;
        }
        while (res2.size() < s2.size()) {
            res2 = '0' + res2;
        }
        cout << "Case #" << l + 1 << ": " << res1 << " " << res2 << endl;
    }
    return 0;
}
