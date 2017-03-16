#include<stdio.h>
typedef long long int lld;
int main() {
    int T, t = 1;
    int k, c, s;
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%d%d%d", &k, &c, &s);
        if(s < (k+c-1)/c) printf("Case #%d: IMPOSSIBLE\n", t);
        else {
            printf("Case #%d:", t);
            for(int b = 0; b < k; ) {
                lld res = 0;
                for(int i = 0; i < c; ++i, ++b) res = res*k+((b<k)?(b):(0));
                printf(" %lld", res+1);
            }
            printf("\n");
        }
    }
    return 0;
}
