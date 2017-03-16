#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list[110];

int main()
{
    int aa, nn, ans = 0;
    int i, n, s, p, t;
    scanf("%d",&nn);
    for ( aa = 1; aa <= nn; ++aa ) {
        scanf("%d %d %d",&n, &s, &p);
        for ( i = 0; i < n; i++ ) {
            scanf("%d",&list[i]);
        }
        ans = 0;
        for ( i = 0; i < n; i++ ) {
            switch (list[i] % 3) {
                case 0:
                    t = list[i]/3;
                    if ( t >= p )
                        ans++;
                    else if (s && list[i] >= 3 && (list[i]-3)/3+2 >= p) {
                        s--;
                        ans++;
                    }
                    break;
                case 1:
                    t = (list[i]-1)/3 + 1;
                    if ( t >= p )
                        ans++;
                    else if ( s && list[i] >= 4 && (list[i]-4)/3+2 >= p) {
                        s--;
                        ans++;
                    }
                    break;
                case 2:
                    t = (list[i]-2)/3 + 1;
                    if ( t >= p)
                        ans++;
                    else if ( s && ++t >= p) {
                        s--;
                        ans++;
                    }
                    break;
            }
        }
        printf("Case #%d: %d\n",aa,ans);
    }
    return 0;
}

