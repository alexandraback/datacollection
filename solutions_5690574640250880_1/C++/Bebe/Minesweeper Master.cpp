#include <cstdio>
#include <iostream>
#define Click 'c'
#define Mine '*'
#define Empty '.'

using namespace std;

int R, C, M;

int solve ()
{
    if ( M == 0 ) return 0;
    if ( R*C-M == 1 ) return 0;
    if ( R != 1 && C != 1 && R*C-M < 4 ) return 1;
    if ( R != 1 && C != 1 && ( R*C-M == 5 || R*C-M == 7 ) ) return 1;
    if ( ( R == 2 || C == 2 ) && M%2 != 0 ) return 1;
    return 0;
}



int main()
{
    freopen("C-Large.in.","r",stdin);
    freopen("CLargeans","w",stdout);
    int t, T, i, j, s;
    scanf("%d",&T);
    for ( t = 0 ; t < T ; t ++ )
    {
        scanf("%d %d %d",&R,&C,&M);
        s = solve();
        printf("Case #%d:\n",t+1);
        if ( s == 0 )
        {
            if ( R*C-M == 1 )
            {
                for ( i = 0 ; i < R ; i ++ )
                {
                    for ( j = 0 ; j < C ; j ++ )
                    {
                        printf("%c", i == 0 && j == 0 ? Click : Mine);
                    }
                    putchar('\n');
                }
            }
            else if ( R == 1 )
            {
                for ( i = 0 ; i < C ; i ++ )
                {
                    printf("%c",i == 0 ? Click : ( i < C-M ? Empty : Mine ) );
                }
                putchar('\n');
            }
            else if ( C == 1 )
            {
                for ( i = 0 ; i < R ; i ++ )
                {
                    printf("%c\n",i == 0 ? Click : ( i < R-M ? Empty : Mine ) );
                }
            }
            else
            {
                int scnt = R*C-M, flag = 0, rc = 0;
                if ( scnt >= C*2 && scnt-C*2 != 1 )
                {
                    for ( i = 0 ; i < C ; i ++ )
                    {
                        printf("%c",flag == 0 ? Click : Empty );
                        flag = 1;
                    }
                    putchar('\n');
                    for ( i = 0 ; i < C ; i ++ )
                    {
                        printf(".");
                        flag = 1;
                    }
                    putchar('\n'); scnt -= C*2; rc += 2;
                    while ( scnt >= C && scnt-C != 1 )
                    {
                        for ( i = 0 ; i < C ; i ++ )
                        {
                            printf(".");
                            flag = 1;
                        }
                        putchar('\n'); scnt -= C; rc += 1;
                    }
                    if ( scnt == C+1 )
                    {
                        for ( i = 0 ; i < C ; i ++ )
                        {
                            printf("%c",i < (scnt+1)/2 ? Empty : Mine );
                        }
                        putchar('\n'); scnt -= (scnt+1)/2; rc +=1;
                        for ( i = 0 ; i < C ; i ++ )
                        {
                            printf("%c",i < scnt ? Empty : Mine );
                        }
                        putchar('\n'); scnt = 0; rc +=1;
                        for ( i = rc ; i < R ; i ++ )
                        {
                            for ( j = 0 ; j < C ; j ++ )
                                printf("*");
                            putchar('\n');
                        }
                    }
                    else
                    {
                        if ( rc == R ) continue;
                        for ( i = 0 ; i < C ; i ++ , scnt -- )
                        {
                            printf("%c",scnt > 0 ? Empty : Mine );
                        }
                        putchar('\n'); rc += 1;
                        for ( i = rc ; i < R ; i ++ )
                        {
                            for ( j = 0 ; j < C ; j ++ )
                                printf("*");
                            putchar('\n');
                        }
                    }
                }
                else
                {
                    for ( i = 0 ; i < C ; i ++ )
                    {
                        if ( scnt-2*i != 1 && scnt-2*i <= i ) break;
                    }
                    if ( i == C ) printf("ERROR!\n");
                    else
                    {
                        for ( j = 0 ; j < C ; j ++ )
                        {
                            printf("%c", j == 0 ? Click : ( j < i ? Empty : Mine ) );
                        }
                        putchar('\n'); rc += 1;
                        for ( j = 0 ; j < C ; j ++ )
                        {
                            printf("%c", j < i ? Empty : Mine );
                        }
                        putchar('\n'); rc += 1; scnt -= i*2;
                        if ( rc == R ) continue;
                        for ( j = 0 ; j < C ; j ++ )
                        {
                            printf("%c", j < scnt ? Empty : Mine );
                        }
                        putchar('\n'); rc += 1; scnt = 0;
                        for ( i = rc ; i < R ; i ++ )
                        {
                            for ( j = 0 ; j < C ; j ++ )
                                printf("*");
                            putchar('\n');
                        }
                    }
                }
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }

    return 0;
}
