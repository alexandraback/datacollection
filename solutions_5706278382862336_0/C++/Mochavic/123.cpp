#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int T, ri = 1, i;
    long long p, q, t;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%lld/%lld", &p, &q);
        t = __gcd(p, q);
        p /= t; q /= t;
        for (i = 0; i < 40; i++){
            if (q % 2 == 0) q /= 2;
            else p *= 2;
        }
        printf("Case #%d: ", ri++);
        if (q > 1) printf("impossible\n");
        else{
            for (i = 39; i >= 0; i--){
                if (p & (1ll<<i)){
                    break;
                }
            }
            printf("%d\n", 40 - i);
        }
    }
    return 0;
}
