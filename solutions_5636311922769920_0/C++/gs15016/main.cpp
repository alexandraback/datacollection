#include <cstdio>
#include <algorithm>

using namespace std;

int tc, ttc;
long long k, c, s;

int main(){
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    scanf("%d", &tc);
    for(ttc = 1; ttc <= tc; ttc++){

        scanf("%lld%lld%lld", &k, &c, &s);

        printf("Case #%d: ", ttc);

        long long a = 1;
        for(int i = 0; i < c - 1; i++) a *= k;

        for(int i = 0; i < s; i++){
            printf("%lld ", a * i + 1);
        }
        puts("");
    }
}
