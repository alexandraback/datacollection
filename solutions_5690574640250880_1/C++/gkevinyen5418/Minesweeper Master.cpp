#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int T;
char bg[60][60];
int R, C, M;

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        scanf("%d %d %d", &R, &C, &M);

        printf("Case #%d:\n", Ti);

        if( R*C-M == 1 )
        {
            for(int Ri = 0; Ri < R; Ri++)
                for(int Ci = 0; Ci < C; Ci++)
                {
                    if( Ri == 0 && Ci == 0 ) printf("c");
                    else printf("*");

                    if( Ci+1 == C ) puts("");
                }
        }

        else if( R == 1 || C == 1 )
        {
            int cnt = 1;

            for(int Ri = 0; Ri < R; Ri++)
                for(int Ci = 0; Ci < C; Ci++)
                {
                    if( Ri == 0 && Ci == 0 ) printf("c");
                    else if( cnt < R*C-M ) printf("."),cnt++;
                    else printf("*");

                    if( Ci+1 == C ) puts("");
                }
        }
        else if( R*C-M < 4 ) puts("Impossible");
        else
        {
            for(int Ri = 0; Ri < R; Ri++)
                for(int Ci = 0; Ci < C; Ci++)
                    bg[Ri][Ci] = '*';

            bg[0][0] = 'c';
            bg[0][1] = bg[1][0] = bg[1][1] = '.';

            int now = R*C-M-4;
            int t = max(R, C);

            int _r = 0, _c = 0;

            for(int ti = 2; ti < t && now > 1; ti++)
            {
                if( ti < R && now > 1 ) bg[ti][0] = bg[ti][1] = '.', now -= 2, _r = ti;
                if( ti < C && now > 1 ) bg[0][ti] = bg[1][ti] = '.', now -= 2, _c = ti;
            }

            for(int Ri = 2; Ri <= _r; Ri++)
                for(int Ci = 2; Ci <= _c && now > 0; Ci++)
                    bg[Ri][Ci] = '.', now--;

            if( now > 0 ) puts("Impossible");
            else
            {
                for(int Ri = 0; Ri < R; Ri++)
                    for(int Ci = 0; Ci < C; Ci++)
                    {
                        printf("%c", bg[Ri][Ci]);
                        if( Ci+1 == C ) puts("");
                    }
            }
        }
    }
}
