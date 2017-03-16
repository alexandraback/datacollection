#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cstring>
#include <string.h>
using namespace std;
const int maxn = 110;
long long int a[maxn], b[maxn], c[maxn], d[maxn];
long long int cost[maxn][maxn], now,f[maxn][maxn][maxn], g[maxn][maxn], ff[maxn][maxn];
int test, n, m;

long long max(long long a, long long b) {
    if (a > b) return a; else return b;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n >> m; int nn = 1, mm = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &b[nn], &a[nn]);
            if (a[nn] == a[nn - 1]) { nn--; b[nn] += b[nn + 1];}
            nn++;
        }
        memset(f, 0, sizeof(f)); memset(ff, 0, sizeof(ff));
        //printf("%lld", f[1][1][1]);
        for (int i = 1; i <= m; i++) {
            scanf("%lld%lld", &d[mm], &c[mm]);
            if (c[mm] == c[mm - 1]) {mm--; d[mm] += d[mm + 1];}
            mm++;
        }
        for (int j = 1; j <= 100; j++) cost[0][j] = 0;
        for (int i = 1; i <=m ;i++) {
            for (int j = 1; j <= 100; j++) cost[i][j] = cost[i - 1][j];
            cost[i][c[i]] += d[i];
        }
        nn--; mm--;
        n = nn; m = mm;
        //cout << n << ' ' << m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ff[i][j] = max(ff[i][j-1],ff[i-1][j]);
                now = b[i];
                for (int l = i - 1; l >= 0; l--) {
                    for (int k = 0; k <= j; k++) {
                        long long c = cost[j][a[i]] - cost[j - k][a[i]];
                        //cout << j - k << ' ' <<   j << ' ' << c << endl;
                        if (ff[l][j - k] + min(c, now) > f[i][j][k]) f[i][j][k] = ff[l][j - k] + min(c, now);
                        if (f[i][j][k] > ff[i][j])  { g[i][j] = k; ff[i][j] = f[i][j][k];}
                    }
                    if (a[l] == a[i]) now += b[l];
                }
                //cout << i << " " << j << ' ' << ff[i][j] << endl;
            }

        }
        cout << "Case #" << t << ": ";
        cout << ff[n][m] <<  endl;
    }
    return 0;
}
        /*
        for (int i = 1; i <= nn; i++) {
            for (int j = 1; j <= mm; j++) {
                for (int l = 1; l <= mm;l++) {
                    long long ty = 0; long long now = b[i];
                    for (int k = j; k >= 0; k--) {
                        if (f[i - 1][k] + ty > f[i][j]) f[i][j] = f[i - 1][k] + ty;
                        if (c[k] == a[i]) { if (now > d[i]) {ty+=d[i];now-=d[i];} else {ty+=now;now=0;}}
                    }
                }
            }
        }*/
  /*      for (int i = 1;i <= n; i++) {
            for (int j = 1; j<= m;j++) {
                f[i][j] = f[i][j - 1];
                if (f[i - 1][j] < f[i][j]) f[i][j] = f[i - 1][j];
                for (int ss = 1; ss <= 100; ss++) cost[ss] = 0;
                for (int k = i; k >= 1; k--) {
                    cost[a[k]] += b[k];
                    for (int ss = 1; ss <= 100; ss++) now[ss] = cost[ss];
                    long long ty = 0;
                    for (int l = j; l >= 1; l--) {
                        if (now[c[l]] > d[l]) {now[c[l]] -= d[l]; ty += d[l];} else
                        {
                            ty += now[c[l]]; now[c[l]] = 0;
                        }
                        if (ty + f[k - 1][l - 1] > f[i][j]) f[i][j] = ty + f[k - 1][l - 1];
                    }
                }

            }
        }*/
