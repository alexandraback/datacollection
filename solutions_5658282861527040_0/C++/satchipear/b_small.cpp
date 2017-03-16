#include <stdio.h>

int main() {
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        int ans = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int x = i & j;
                if (x < k) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", cn, ans);
    }
    return 0;
}
