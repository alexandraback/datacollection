#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
//#define double long double
#define merge botva
#define double long double
#define time botva1

#ifdef ONLINE_JUDGE
#define olo "%I64d\n"
#define jolo "%011I64d"
#else
#define olo "%lld\n"
#define jolo "%011Ld"
#endif

#define satan2 atan2
const int maxn = 420, maxlen = 502 * 502 + 20, consta = 1050, maxi = consta + 4, big = 10000000;
//magic = 239, magic1 = 359;
const long long INF = 1000000000;
const char BLANK = '-', FULL = '#';

long long a[maxn], A[maxn], b[maxn], B[maxn];
int n;
long long sum = 0;

int usd[maxn];
int magic = 1;
bool lold;

long long dp[maxn][maxn];
long long hma[maxn][maxn], hmb[maxn][maxn];

int main() {
    //freopen("complexity.in", "r", stdin);
    //freopen("complexity.out", "w", stdout);
   
    int h, m, t, v;
    cin >> t;
                //from who
    for (int ti = 1; ti <= t; ++ti) {
        //cin >> n;
        //lold = 0;
        //n = 20;
        //was.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> A[i];
            if (A[i] == A[i - 1]) {a[i - 1] += a[i];
            --i; --n;}
        } 
        //cout << "m is " << m << endl;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i] >> B[i];
            if (B[i] == B[i - 1]) {b[i - 1] += b[i];
            --i; --m;
            }
        }
        for (int i = 1; i <= 100; ++i)
            hma[0][i] = 0, hmb[0][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 100; ++j)
                hma[i][j] = hma[i - 1][j];
            hma[i][A[i]] += a[i];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= 100; ++j)
                hmb[i][j] = hmb[i - 1][j];
            hmb[i][B[i]] += b[i];
        }
        long long res =0; 
        //cout << "m is " << m << endl;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                for (int k = 1; k <= i; ++k)
                    if (hmb[j][A[k]] > 0)
                        for (int l = 1; l <= j; ++l) {
                            if (hmb[j][A[k]] - hmb[l - 1][A[k]] == 0) break;
                            dp[i][j] = max(dp[i][j], min(hma[i][A[k]] - hma[k - 1][A[k]], 
                                                    hmb[j][A[k]] - hmb[l - 1][A[k]]) + dp[k - 1][l - 1]);
                        }
            }
        
                
        printf("Case #%d: ", ti);
        cout << dp[n][m] << endl;
        //for (int i = 1; i <= n; ++i)
        //    e[i].clear();
    }

}
