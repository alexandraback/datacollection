#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T, tt;
    freopen("A-small-attempt1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (tt = 0; tt < T; ++tt) {
        long long r, t;
        scanf("%lld%lld", &r, &t);
        long long left = -(2*r-1) / 4;
        long long rig = 0x7fffffff - 1;
        while (left <= rig) {
            long long mid = (left+rig)/2;
            if (2*mid*mid + (2*r-1)*mid -t > 0)rig = mid-1;
            else left = mid + 1;
        }
        printf("Case #%d: %lld\n", tt+1, rig);
    }
    return 0;
}
