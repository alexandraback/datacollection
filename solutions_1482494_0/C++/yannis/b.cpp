#include <cstdio>
#include <cstdlib>

int a[1010], b[1010], sofar[1010];
int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, T, t, n, st, ch, lvl;

    scanf("%d", &T);
    for(t=1; t<=T; ++t) {
        scanf("%d", &n);
        for (i=1; i<=n; ++i) {
            scanf("%d %d", &a[i], &b[i]);
            sofar[i] = 0;
        }

        int p = 0, stars = 0, ans = 0;
        while(stars < 2*n) {
            ch = -1;
            for (i=1; i<=n; ++i) {
                if ( sofar[i] == 2 ) continue;
                if ( sofar[i] == 0 && stars >= b[i] ) {
                    ch = i; lvl = 2; break;
                }
                if ( sofar[i] == 1 && stars >= b[i] ) {
                    ch = i; lvl = 2; break;
                }
                else if ( sofar[i] == 0 && stars >= a[i] ) {
                    if ( ch == -1 || ( b[ch] < b[i] ) ) { ch = i; lvl = 1; }
                }
            }

            if ( ch != -1 ) {
                stars += lvl-sofar[ch];
                sofar[ch] = lvl;
                ans++;
            }
            else break;
        }

        if ( stars == 2*n ) {
            printf("Case #%d: %d\n", t, ans);
        }
        else {
            printf("Case #%d: Too Bad\n", t);
        }
    }

    return 0;
}
