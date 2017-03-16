#include <cstdio>
#include <cstring>

typedef long long LL;

bool check(LL r, LL t, LL k) {
    if (t / k / 2 < k) return 0;
    t -= k * k * 2;
    t += k;
    if (t / k / 2 < r) return 0;
    return 1;
}

int main() {
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; ++ T) {
        LL r, t, ans = 0;
        scanf("%lld%lld", &r, &t);
        LL lower = 1, upper = 707106781;
        while (lower <= upper) {
            LL mid = (lower + upper) >> 1;
            if (check(r, t, mid)) {
                ans = mid;
                lower = mid + 1;
            } else upper = mid - 1;
        }
        printf("Case #%d: %lld\n", T, ans);
    }
    return 0;
}
