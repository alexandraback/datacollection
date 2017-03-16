#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
int main() {
    int T,ca = 1;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out","w",stdout);
    scanf("%d", &T);
    while(T--) {
        int A,B,C;
        int ret = 0;
        scanf("%d%d%d",&A,&B,&C);
        for(int i = 0; i < A; i++) {
            for(int j = 0; j < B; j++) {
                if((i & j)  < C) {
                    ret++;
                }
            }
        }
        printf("Case #%d: %d\n", ca++, ret);
    }
}
