#include<stdio.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

int main(){
    int T, u;
        scanf("%d", &T);
    for (u = 1 ; u <= T ; ++u){
        long long a, t;
        scanf("%I64d%I64d", &a, &t);
        long long l = 1, m, r = MIN(707106781, t / (a * 2 + 1) + 1);
        while (l < r - 1){
            m = (l + r) / 2;
            if (((a * 4 + 2) + (4 * m - 4)) * m / 2 <= t)
                l = m;
            else r = m;
        }
        printf("Case #%d: %I64d\n", u, l);
    }
    return 0;
}
