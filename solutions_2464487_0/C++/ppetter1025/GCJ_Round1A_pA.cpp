#include <cstdlib>
#include <cstdio>
#include <cmath>

//#define test

using namespace std;

typedef long long ll;

inline bool c(ll k, ll r, ll t) {
    return ((2 * k * r + 2 * k * k - k) <= t);
}

ll solve(ll r, ll t) {
    long long int lb = 0, ub = 1000000000;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(c(mid, r, t))    lb = mid;
        else    ub = mid;
        #ifdef test
        printf("%lld|\n", mid);
        #endif // test
    }

    return lb;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int p = 0; p < t; p++) {
        printf("Case #%d: ", p + 1);

        ll r, t;
        scanf("%lld %lld", &r, &t);

        printf("%lld\n", solve(r, t));
    }
}
