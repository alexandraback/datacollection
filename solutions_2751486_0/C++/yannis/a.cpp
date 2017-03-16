#include <cstdio>
#include <stdlib.h>
#include <string.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T, n, cc, i, j, len;
    long long ans;
    char str[1000010];
    int e[1000010], ep;

    scanf("%d\n", &T);

    for (t=1; t<=T; ++t) {
        scanf("%s %d\n", str, &n);

        len = strlen(str); cc = 0; ep = 0;
        for (i=0; i<len; ++i) {
            if ( str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' ) {
                cc++;
                if ( cc >= n ) {
                    e[ep++] = i;
                }
            }
            else { cc = 0; }
        }

        ans = 0; j = 0;
        for (i=0; i<len; ++i) {
            for (; j<ep; ++j) {
                if ( i+n-1 <= e[j] && e[j] >= i ) break;
            }
            if ( j == ep ) break;
            ans += len-e[j];
        }

        printf("Case #%d: %lld\n", t, ans);
    }

    return 0;
}
