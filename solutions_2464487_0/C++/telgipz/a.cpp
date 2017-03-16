#include <cstdio>

using namespace std;

long long sumsq(long long x) {
    return x*(x+1)*(x+2)/6LL;
}

long long innersum(long long a, long long b) {
    b*=2;
    long long out=sumsq(b);
        out-=sumsq(a);
    if (a+1<=b-1) {
        out+=-sumsq(b-1);//+sumsq(a+1);
    }
    return out;
}

long long calc(long long a, long long b) {

    //b*=2;
    long long out;//=b*(b+1)*(2*b+1)/6 - b*(b+1)*(b-1)/3;
    out=innersum(a, b);
    
    
    return out;
}

long long calcx(long long x) {
    return -1*x*x+(x+1)*(x+1);
}

int main() {
    long long t, a, b;
    freopen("a.in", "r", stdin);
    freopen("a.sol", "w", stdout);
    scanf("%lld", &t);
    for (long long test=1; test<=t; test++) {
        scanf("%lld %lld", &a, &b);
        printf("Case #%lld: ", test);
        long long  out =0;
        while (calcx(a)<=b) {
            b-=calcx(a);
            a+=2;
            out++;
            
        }
        printf("%lld\n", out);
        //printf("%lld\n", calc(0, 3));
    }
    
    
    return 0;
}