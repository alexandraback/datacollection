#include <cstdio>

int a[12345];

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        int n; scanf("%d", &n);
        int ans = 123456;
        for (int i = 0; i < n ; ++i) scanf("%d", a + i);
        for (int pile = 1; pile <= 1000; ++pile) {
            int now = pile;
            for (int j = 0; j < n; ++j) now += (a[j] - 1 ) / pile;
            if (now < ans) ans = now;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
