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

vector <string> v = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    int t;
    cin >> t;
    FOR (l, 0, t) {
        string s;
        cin >> s;
        map <char, int> ss;
        for (auto i: s) {
            ++ss[i];
        }
        vector <int> ans(10);
        ans[0] = ss['Z'];
        FOR (k, 0, ans[0]) {
            for (auto j: v[0]) {
                --ss[j];
            }
        }
        ans[2] = ss['W'];
        FOR (k, 0, ans[2]) {
            for (auto j: v[2]) {
                --ss[j];
            }
        }
        ans[6] = ss['X'];
        FOR (k, 0, ans[6]) {
            for (auto j: v[6]) {
                --ss[j];
            }
        }
        ans[8] = ss['G'];
        FOR (k, 0, ans[8]) {
            for (auto j: v[8]) {
                --ss[j];
            }
        }
        ans[4] = ss['U'];
        FOR (k, 0, ans[4]) {
            for (auto j: v[4]) {
                --ss[j];
            }
        }
        ans[7] = ss['S'];
        FOR (k, 0, ans[7]) {
            for (auto j: v[7]) {
                --ss[j];
            }
        }
        ans[5] = ss['V'];
        FOR (k, 0, ans[5]) {
            for (auto j: v[5]) {
                --ss[j];
            }
        }
        ans[1] = ss['O'];
        FOR (k, 0, ans[1]) {
            for (auto j: v[1]) {
                --ss[j];
            }
        }
        ans[3] = ss['T'];
        FOR (k, 0, ans[3]) {
            for (auto j: v[3]) {
                --ss[j];
            }
        }
        ans[9] = ss['I'];
        FOR (k, 0, ans[9]) {
            for (auto j: v[9]) {
                --ss[j];
            }
        }
        for (auto i: ss) {
            if (i.second != 0) {
                DEB(l);
                DEB(s);
                exit(0);
            }
        }
        cout << "Case #" << l + 1 << ": ";
        FOR (i, 0, 10) {
            FOR (j, 0, ans[i]) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
