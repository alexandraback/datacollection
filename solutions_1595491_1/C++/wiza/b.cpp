#include <stdio.h>

int ans, cnt;

void solve(int x, int p) {
    int m = x % 3;
    int n = x / 3;
    switch (m) {
        case 0: {
            if (n >= p) ans++;
            else if (cnt && n &&  n + 1 >= p) ans++, cnt--;
            break;
        }
        case 1: {
            if (n + 1 >= p) ans++;
            break;
        }
        case 2: {
            if (n + 1 >= p) ans++;
            else if (cnt && n + 2 >= p) ans++, cnt--;
            break;
        }
    }
}

int main() {
    int i, n, t;
    int s, p, x;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d %d %d", &n, &s, &p);
        ans = 0;
        cnt = s;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            solve(x, p);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
