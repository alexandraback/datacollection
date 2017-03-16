#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);

    int T, c, d, i, j, cas = 1;
    long long v, dt[105], vt[105], ans, p;

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %lld", &c, &d, &v);

        for( i = 0; i < d; ++i ) scanf("%lld", &dt[i]);

        ans = 0;
        sort(dt, dt+d);
        if( dt[0] != 1 ) {
            dt[d] = dt[0];
            dt[0] = 1;
            ++d;
            ++ans;
        }

        p = c;
        i = 1;
        while( p < v ) {
            if( i < d && p >= dt[i]-1 ) {
                p += dt[i]*c;
                ++i;
            }
            else {
                ++ans;
                p += (p+1)*c;
            }
        }

        printf("Case #%d: %d\n", cas++, ans);
    }


    return 0;
}
