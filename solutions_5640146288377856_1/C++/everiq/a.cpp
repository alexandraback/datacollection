#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int qq = 1; qq <= t; ++qq) {
        int r, c, w;
        scanf("%d %d %d", &r, &c, &w);
        int ans = 0;
        if (w == 1) ans = c * r;
        else {
            ans = (c / w) * r + w;
            if (c % w == 0) --ans;
        }
        printf("Case #%d: %d\n", qq, ans);
    }
    return 0;
}
