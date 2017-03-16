#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define LD long double
#define VI vector<int>
#define PB push_back
#define MP make_pair
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) printf("%d ", x)
#define wl(x) printf("%d\n", x)
#define N 111

int n, m, k, t, p, v[N], f[N][N], r, e, T;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    re(T);
    for (int _ = 1; _ <= T; _++) {
        memset(f,0,sizeof(f));
        scanf("%d%d%d", &e, &r, &n);
        int maxn = 0;
        for (int i = 1; i <= n; i++) re(v[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= e; j++) {
                for (int p = 0; p <= j; p++) {
                    if (j-p+r >= e) f[i][e] = max(f[i][e], f[i-1][j] + p*v[i]);
                    if (j-p+r <= e) f[i][j-p+r] = max(f[i][j-p+r], f[i-1][j] + p*v[i]);
                }
            }
        }
        for (int i = 0; i <= e; i++) {
            maxn = max(f[n][i], maxn);
        }
        printf("Case #%d: %d\n", _, maxn);
    }
    return 0;
}

