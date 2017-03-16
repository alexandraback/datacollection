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
        while (n < 3) {
            ++n;
            a[n] = 0;
            A[n] = -1;
        }
        //cout << "m is " << m << endl;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i] >> B[i];
            if (B[i] == B[i - 1]) {b[i - 1] += b[i];
            --i; --m;
            }
        }
        long long res =0;
        if (A[1] == A[3]) {
            long long mres = 0;
            for (int i = 1; i <= m; ++i)
                if (B[i] == A[3])
                    mres +=b[i];
            mres = min(mres, a[1] + a[3]);
            res = max(res, mres);
        } 
        //cout << "m is " << m << endl;
        for (int i = 0; i <= m; ++i)
            for (int j = i; j <= m; ++j) {
                //cout << i << ".." << j << endl;
                long long ares, bres, cres;
                ares = bres = cres = 0;
                for (int k = 1; k <= m; ++k)
                    if (k <= i) { if (B[k] == A[1])
                        ares += b[k];
                    } else if (k <= j) {
                        if (B[k] == A[2])
                            bres += b[k];
                    } else 
                        if (B[k] == A[3])
                            cres += b[k];
                //cout << ares << " " << bres << " " << cres << endl;
                ares = min(ares, a[1]);
                bres = min(bres, a[2]);
                cres = min(cres, a[3]);
                res = max(res, ares+ bres+cres);
            }
                
        printf("Case #%d: ", ti);
        cout << res << endl;
        //for (int i = 1; i <= n; ++i)
        //    e[i].clear();
    }

}
