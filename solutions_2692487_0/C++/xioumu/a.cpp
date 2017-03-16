/*
 * Author:  xioumu
 * Created Time:  2013/5/5 0:28:10
 * File Name: a.cpp
 * solve: a.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double eps = 1e-8;
const int maxn = 100 + 10;
const int maxm = 1000000 + 7;
const int limm = 1000000;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int n, m;
int f[maxn][maxm], a[maxn];

int main() {
    int T, ca = 1;
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        memset(f, 10, sizeof(f));
        repf (i, 1, n) 
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        f[0][m] = 0;
        repf (i, 0, n) {
            repf (j, 0, limm) { 
                int h;
                if (i > 0 && j > a[i]) {
                    h = min(limm, j + a[i]);
                    f[i][h] = min(f[i - 1][j], f[i][h]);
                }
                if (i > 0) {
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j]);
                }
                if (j != 0) {
                    h = min(limm, j - 1 + j);
                    f[i][h] = min(f[i][j] + 1, f[i][h]);
                }
            }
        }
        int ans = maxint;
        repf (i, 0, limm)
            ans = min(ans, f[n][i]);
        printf("Case #%d: ", ca++);
        printf("%d\n", ans);
    }
    return 0;
}
