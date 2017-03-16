/*
Author: LotK
LANG: C++
*/

#include <cstdio>

int a[210];
int used[210];
double ans[210];
int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

    int t, tt, i, j, n, X;
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        scanf("%d", &n);
        X = 0;
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            X += a[i];
            used[i] = 0;
        }
        int tmpn = n;
        int X2 = X*2;
        while(1) {
            for(i=0 ; i<n ; i++) {
                if(used[i]==1) {
                    ans[i] = 0;
                    continue;
                }
                ans[i] = (1.0*(X2)/tmpn - a[i])/X*100.0;
                if(ans[i] < 0) {
                    used[i]=1;
                    X2 -= a[i];
                    tmpn--;
                    break;
                }
            }
            if(i==n) break;
        }


        printf("Case #%d: ", t+1);
        for(i=0 ; i<n ; i++) {
            printf("%lf ", ans[i]);
        }
        printf("\n");
    }
}
