#include<stdio.h>
#include<string.h>


unsigned long long GCD(unsigned long long  a,unsigned long long  b) {
        unsigned long long  temp;
            if ( a % b == 0 ) {
                return b;      
            } else {
                return GCD(b, a % b);
            }       
}

void main() {
    int i, t;
    unsigned long long p, q, a, gcd;
    scanf("%d", &t);
    for (i = 1 ; i <= t ; i++) {
        scanf("%llu/%llu", &p, &q);
        int ans = 0;
        gcd = GCD(p, q);
        p = p / gcd;
        q = q / gcd;
        while (p < q) {
            p = p * 2;
            ans++;
        }
        for (a = 1; a < q ; a = a *2) {
        
        }
        if (a == q && ans < 41) {
            printf("Case #%d: %d\n", i, ans);   
        } else {
            printf("Case #%d: impossible\n", i);   
        }
    }
}
