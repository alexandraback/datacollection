#include <cstdio>
#define HUGE 807106780LL;

int main() {
long long _t; scanf("%lld", &_t);
for(long long _i=1; _i<=_t; _i++) {
printf("Case #%d: ", _i);
    long long r, t; scanf("%lld %lld", &r, &t);
    long long mi=1, ma=HUGE;
    while(ma-mi>1) {
        long long mid = (mi+ma)/2;
        long long area = 2*r*mid+2*(mid-1)*(mid)+mid;
        if(area <= t) {
            mi = mid;
        } else {
            ma = mid;
        }
    }
    printf("%lld\n", mi);
}
}
