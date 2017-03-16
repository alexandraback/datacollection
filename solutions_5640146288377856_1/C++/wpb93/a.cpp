#include <cstdio>

int main() {
    int T, r, c, w, ans;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &r, &c, &w);
        ans = r * c / w + w;
        if (c % w == 0) ans--;
        printf("%d\n", ans);
    }
    return 0;
}
