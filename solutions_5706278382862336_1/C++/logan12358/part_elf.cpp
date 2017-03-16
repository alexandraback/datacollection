#include <cstdio>

long long gcd(long long p, long long q) {
    while(q!=0) {
        long long t=q;
        q = p%q;
        p = t;
    }
    return p;
}

int main() {
    long long _t; scanf("%lld", &_t);
    for(long long _i=1; _i<=_t; _i++) {
        long long p, q; scanf("%lld/%lld", &p, &q);
        long long g = gcd(p, q);
        q/=g;
        p/=g;
        g=q;
        while(g%2==0) g/=2;
        if(g!=1) printf("Case #%lld: impossible\n", _i);
        else {
            long long i=1;
            while(2*p<q && q%2==0) {
                i++;
                q/=2;
            }
            printf("Case #%lld: %lld\n", _i, i);
        }
    }
}
