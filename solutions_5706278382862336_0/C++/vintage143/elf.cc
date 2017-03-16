#include <cstdio>

long long gcd(long long a, long long b) { 
 return b ? gcd(b, a % b) : a; 
} 

bool isPow2(long long a){
    return (a & (a-1)) == 0;
}

int main(int argc, char const *argv[])
{
    int tests;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; t++) {
        long long P, Q;
        scanf("%lld /%lld", &P, &Q);
        long long factor = gcd(P, Q);
        P /= factor;
        Q /= factor;
        if(!isPow2(Q)) {
            printf("Case #%d: impossible\n", t);
        } else {
            if(P < Q/2) {
                int i = 0;
                while(Q > 1) {
                    Q >>= 1;
                    i++;
                }
                int j = 0;
                while(P > 1) {
                    P >>= 1;
                    j++;
                }
                printf("Case #%d: %d\n", t, i-j);
            } else {
                printf("Case #%d: 1\n", t);
            }
        }
    }
    return 0;
}