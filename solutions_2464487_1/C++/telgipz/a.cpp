#include <cstdio>

using namespace std;

unsigned long long int sumsq(unsigned long long int x) {
    if (x<=0) return 0;
    return x*(x+1)*(x+2)/6LL;
}

unsigned long long int sum(unsigned long long int b, unsigned long long int oddeven) {
    unsigned long long int out=sumsq(b)-sumsq(b-1);
    if(!oddeven) out=sumsq(b-1)-sumsq(b-2);
    return out;
}


unsigned long long int calcx(unsigned long long int x, unsigned long long int inner) {
    return sum(x*2+inner-1, 1)-sum(inner-1, 1);
}

int main() {
    unsigned long long int t, a, b;
    freopen("a.in", "r", stdin);
    freopen("a.sol", "w", stdout);
    //printf("%llu\n", sum(3*2+3-1, 1)-sum(3-1, 1));
    
    //printf("%llu\n", calcx(442297794LL,71));
    //return 0;
    scanf("%llu", &t);
    for (unsigned long long int test=1; test<=t; test++) {
        scanf("%llu %llu", &a, &b);
        printf("Case #%llu: ", test);
        unsigned long long int hi=707106782LL, lo=1;
        while (lo<=hi) {
            unsigned long long int mid=lo+(hi-lo)/2LL;
            //printf("(%llu %llu %llu)", hi ,lo,mid);
            /*if(calcx(mid,a)==b) {
                lo=mid;
                break;
            }*/
            if (calcx(mid,a)<b) {
                lo=mid+1;
            }else hi=mid-1;
        }
        printf("%llu\n", hi);
        //printf("%llu\n", out);
        //printf("%llu\n", calc(0, 3));
    }
    
    
    return 0;
}