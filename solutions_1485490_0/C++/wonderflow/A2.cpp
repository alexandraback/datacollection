#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a)>(b)?(a):(b)

#define LL long long

int n, m;
LL sum1[150], sum2[150], tp1[150], tp2[150], ans2;

void findans(int i, LL lt, int j, LL rt, LL ans) {
    if (i > n || j > m) {
        ans2 = max(ans2, ans);
        return;
    }
    if (tp1[i] == tp2[j]) {
        if (lt < rt) {
            findans(i + 1, sum1[i + 1], j, rt - lt, ans + lt);
        } else {
            findans(i, lt - rt, j + 1, sum2[j + 1], ans + rt);
        }
        return;
    }
    findans(i + 1, sum1[i + 1], j, rt, ans);
    findans(i, lt, j + 1, sum2[j + 1], ans);
}

int main() {
    int T, icas = 0, i;
 	freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lld%lld", sum1 + i, tp1 + i);
        for (i = 1; i <= m; i++)
            scanf("%lld%lld", sum2 + i, tp2 + i);
        ans2 = 0;
        findans(1, sum1[1], 1, sum2[1], 0);
        printf("Case #%d: %lld\n", ++icas, ans2);
    }
    return 0;
}

