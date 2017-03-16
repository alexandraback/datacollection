#include <cstdio>
#include <cmath>

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){

        long long r, lim;
        scanf("%lld %lld" ,&r ,&lim);

        int L = 0, R = 1000000000;
        while(L != R){
            int M = (L + R) / 2 + 1;
            if((2 * (r + M) + 1) <= lim / (M + 1)) L = M;
            else R = M - 1;
        }

        printf("Case #%d: %d\n" ,T ,L + 1);

    }

}

