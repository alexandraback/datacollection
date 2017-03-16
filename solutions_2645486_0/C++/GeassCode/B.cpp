#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 100010
#define LL long long
LL f[110][110];
int val[110];
int E, R, N;
int main() {
    int i, j, k;
    int t, cas;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d", &t);
    for (cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &E, &R, &N);
        for (i = 0; i < N; i++)
            scanf("%d", &val[i]);
        memset(f, -1, sizeof (f));
        f[0][E] = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j <= E; j++) {
                if (f[i][j] == -1)continue;
                for (k = 0; k <= j; k++) {
                    int kk = min(j - k + R, E);
                    f[i + 1][kk] = max(f[i + 1][kk], f[i][j] + k * 1LL * val[i]);
                }
            }
        }
        LL ans=0;
        for (i = 0; i <= E; i++) {
            ans = max(ans, f[N][i]);
        }
        printf("Case #%d: ", cas);
        cout << ans << endl;
    }
    return 0;
}

