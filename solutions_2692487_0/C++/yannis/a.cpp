#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m[15];
    int own, T, t, i, ans, adds;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d", &own, &n);

        for (i=0; i<n; ++i) {
            scanf("%d", &m[i]);
        }

        sort(m, m+n);

        // printf("--%d--\n", own);
        // for (i=0; i<n; ++i) {
        //     printf("%d\n", m[i]);
        // }

        for (i=0; i<n; ++i) {
            if ( own > m[i] ) own += m[i];
            else break;
        }

        ans = n-i;
        /* printf("... %d %d\n", own, ans); */

        adds = 0;
        for (; i<n; ) {
            if ( own > m[i] ) {
                own += m[i];
                ans = min(ans, adds + (n-i-1));
                i++;
            }
            else {
                own += own-1;
                adds++;
                if ( own == 1 ) {
                    i++;
                }
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
