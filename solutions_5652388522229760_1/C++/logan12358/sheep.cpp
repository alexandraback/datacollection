#include <cstdio>

int main() {
    long long int t; scanf("%lld", &t);
    for(long long int _i=1; _i<=t; _i++) {
        long long int n; scanf("%lld", &n);
        long long int used = 0, i, x=n;
        for(i=0; i<10000000; i++) {
            for(long long int j=x; j>0; j/=10) used |= (1<<(j%10));
            if(used==((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9))) break;
            x+=n;
        }
        if(i==100000) printf("Case #%lld: INSOMNIA\n", _i);
        else printf("Case #%lld: %lld\n", _i, x);
    }
}
