#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T, i, j, a, b, k;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d %d", &a, &b, &k);
        int ans = 0;
        for (i=0; i<a; ++i) {
            for (j=0; j<b; ++j) {
                if ( (i&j) < k ) ans++;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
