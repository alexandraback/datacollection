#include<cstdio>
#include<cmath>

long long Min(long long a, long long b){return a<b ?a:b;}

int main(){

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    long long T, n, t;
    scanf("%I64d", &T);

    for (int i=0; i<T; i++){
        scanf("%I64d%I64d", &n, &t);

        long long l = 0, r = Min(t/n, 1000000000);
        while (l < r){

            long long m = (l + r)/2 + 1;

            if ((2*m - 1 + 2*n) * m <= t)    l = m;
            else    r = m - 1;
        }
        printf("Case #%d: %I64d\n", i+1, l);
    }
}
