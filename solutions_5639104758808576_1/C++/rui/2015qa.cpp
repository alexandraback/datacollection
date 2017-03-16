#include <cstdio>
#include <cstdlib>
#include <cstring>

int tt, sm, n, ans, now;
char s[2000];

int main() {
    scanf("%d", &tt);
    for (int t = 1; t <= tt; ++t) {
        scanf("%d %s\n", &sm, s);
        now = s[0] - '0';
        ans = 0;
        for (int i = 1; i <= sm; ++i) {
            int tmp = s[i] - '0';
            if (i > now) {
                ans += i - now;
                now = i;
            }
            now += tmp;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
