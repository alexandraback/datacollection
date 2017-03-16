#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int t;
    long long r, paint;

//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%lld%lld", &r, &paint);
        long long high = min(sqrt(double(paint) / 2), double(paint) / r), low = 1, mid, ret = 1;
        while (high >= low) {
            mid = (high + low) / 2;
            long long req = 2 * mid * r + 2 * mid * mid - mid;
            if (req > paint) high = mid - 1;
            else {
                ret = mid;
                low = mid + 1;
            }
        }

        printf("Case #%d: %lld\n", cas, ret);
    }

    return 0;
}
