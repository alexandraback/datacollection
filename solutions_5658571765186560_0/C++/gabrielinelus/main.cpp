#include <cstdio>

using namespace std;

int main()
{
    freopen("ominous.in","r",stdin);
    freopen("ominous.out","w",stdout);

    int T,R,C,X;
    scanf("%d",&T);
    for(int tst = 1; tst <= T; ++tst)
    {
        scanf("%d%d%d",&X,&R,&C);
        if( (R*C) % X != 0)
            printf("Case #%d: RICHARD\n",tst);
        else
        {
            if(X == 1)
            {
                printf("Case #%d: GABRIEL\n",tst);
                continue;
            }
            if(X == 2)
            {
                printf("Case #%d: GABRIEL\n",tst);
                continue;
            }
            if(X == 3)
            {
                if(R == 1 || C == 1)
                { /// o va alege pe aia L
                    printf("Case #%d: RICHARD\n",tst);
                    continue;
                }
                printf("Case #%d: GABRIEL\n",tst);
                continue;
            }

            if(X == 4)
            {
                if(R < 2 || C < 2)
                {
                    printf("Case #%d: RICHARD\n",tst);
                    continue;
                }
                if(R <= 2 && C < 3 || C <= 2 && R < 3)
                {
                    printf("Case #%d: RICHARD\n",tst);
                    continue;
                }
                if(R < 4 && C < 4)
                {
                    printf("CASE %d: RICHARD\n",tst);
                    continue;
                }
                printf("Case #%d: GABRIEL\n",tst);
            }

        }
    }
    return 0;
}
