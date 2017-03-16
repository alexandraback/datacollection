#include <cstdio>
#include <algorithm>

using namespace std;

int tc, ttc;
long long k, c, s;

int main(){
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    scanf("%d", &tc);
    for(ttc = 1; ttc <= tc; ttc++){

        scanf("%lld%lld%lld", &k, &c, &s);
        if((k + c - 1) / c > s){
            printf("Case #%d: IMPOSSIBLE\n", ttc);
            continue;
        }

        printf("Case #%d: ", ttc);

        long long a = 1, aa, cur = 0;
        for(int i = 0; i < c - 1; i++) a *= k;
        aa = a;
        for(int i = 1; i <= k; i++){
            cur += a * (i - 1);
            a /= k;
            if(i == k || i % c == 0) printf("%lld ", cur + 1), cur = 0, a = aa;
        }
        puts("");
    }
}
