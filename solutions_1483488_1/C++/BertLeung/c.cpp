#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[20];

int main()
{
    int l, i, a, b, aa, nn, d, t, tt;
    int ans;
    scanf("%d",&nn);
    for ( aa = 1; aa <= nn; ++aa) {
        scanf("%d %d",&a,&b);
        sprintf(buffer,"%d",a);
        l = strlen(buffer);
        if ( l == 1 ) {
            printf("Case #%d: 0\n",aa);
            continue;
        }
        for ( d = 1, i = 1; i < l; i++ )
            d *= 10;
        ans = 0;
        for ( i = a; i <= b; i++ ) {
            t = i;
            while (1) {
                tt = t % 10;
                t /= 10;
                t += tt*d;
                if ( t == i )
                    break;
                if ( t <= b && t > i )
                    ans++;
            }
        }
        printf("Case #%d: %d\n",aa, ans);
    }
    return 0;
}

