#include <iostream>
#include <cstdio>
#include <cstdlib>
int C;
long long T, R;
using namespace std;



bool check(long long mid) {
    unsigned long long sum = 0;
    unsigned long long first = 2 * R + 1;
    unsigned long long last = (first + 4 * (mid - 1));
    double f = first;
    double l = last;
    return (f + l) * mid / 2 - 1e-8 < T;
    sum = (first + last) * mid / 2;
    return sum <= T;
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &C);
    for (int cas = 1; cas <= C; cas++) {
        scanf("%I64d%I64d", &R, &T);
        long long ret = 0;
        long long l = 1, r = 2000000000LL;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid)) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        printf("Case #%d: %I64d\n", cas, ret);
    }
    return 0;
}
