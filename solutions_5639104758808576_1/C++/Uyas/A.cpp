#include <cstdio>
#include <cstring>

char s[1111];

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        int n; scanf("%d%s", &n, s);
        int ans = 0, cnt = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > cnt + ans) ans = i - cnt;
            cnt += s[i] - '0';
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

