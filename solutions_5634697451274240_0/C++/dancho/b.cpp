#include <cstdio>
#include <cstring>

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        char buf[1024];
        scanf("%s", buf);
        int n = strlen(buf);
        buf[n] = '+';
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (buf[i] != buf[i + 1]) {
                ++ans;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
