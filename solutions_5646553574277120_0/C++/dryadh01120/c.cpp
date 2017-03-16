#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int T, c, d, v, dt[105], vt[105], i, j, ans, cas = 1;

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &c, &d, &v);

        for( i = 0; i < d; ++i ) scanf("%d", &dt[i]);

        memset(vt, 0, sizeof(vt));
        vt[0] = 1;
        for( i = 0; i < d; ++i ) {
            for( j = v; j >= 0; --j ) {
                if( vt[j] == 1 ) vt[j+dt[i]] = 1;
            }
        }

        ans = 0;
        while(true) {
            for( i = 0; i <= v; ++i ) {
                if( vt[i] == 0 ) {
                    dt[d+ans] = i;
                    break;
                }
            }
            if( i > v ) break;

            for( i = v; i >= 0; --i ) {
                if( vt[i] == 1 ) vt[ i+dt[d+ans] ] = 1;
            }

            ++ans;
        }

        printf("Case #%d: %d\n", cas++, ans);
    }


    return 0;
}
