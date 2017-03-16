#include <stdio.h>

int main(int argc, const char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n, s, p;
        scanf("%d %d %d", &n, &s, &p);
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int total;
            scanf("%d", &total);
            int remain = (total - p) / 2;
//             printf("remain %d\n", remain);
//             printf("p %d\n", p);
//             printf("s %d\n", s);
            if (total < p) {
                continue;
            }
            if (remain >= p - 1) {
                ans++;
            }
            else if (remain == p - 2) {
                if (s) {
                    ans++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
