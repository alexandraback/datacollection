#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int table[5][5];

int main()
{
    char ch;
    Int i,j,in;
    Int n;
    bool blocked;
    Int foundwinner=0;
    Int sum;
    bool TExist=false;

    scanf("%lld",&n);

    for (i=1;i<=n;i++)
    {
        foundwinner=0;

        for (j=1;j<=4;j++)
        {
            for (in=1;in<=4;in++)
            {
                scanf("%c",&ch);

                if (ch!='T' && ch!='O' && ch!='X' && ch!='.')
                {
                    in--;
                }
                else
                {
                    switch (ch)
                    {
                        case 'T':
                        table[j][in]=0;
                        break;

                        case 'O':
                        table[j][in]=-1;
                        break;

                        case 'X':
                        table[j][in]=1;
                        break;

                        case '.':
                        table[j][in]=999;
                        break;
                    }
                }
            }
        }
        //////////////////////////////////////////////////////
        for (j=1;j<=4;j++)
        {
            sum=0;
            TExist=false;
            for (in=1;in<=4;in++)
            {
                if (table[j][in]==0)
                {
                    TExist=true;
                }
                sum=sum+table[j][in];
            }

            if (sum==-4 || (sum==-3 && TExist))
            {
                foundwinner=2;
                break;
            }
            if (sum==4 || (sum==3 && TExist))
            {
                foundwinner=1;
                break;
            }
        }
        ///////////////////////////////////////////////////////////
        if (foundwinner!=0)
        {
            if (foundwinner==1)
            {
                printf("Case #%lld: X won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }
            if (foundwinner==2)
            {
                printf("Case #%lld: O won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }

            continue;
        }
        //////////////////////////////////////////////////////////
        for (j=1;j<=4;j++)
        {
            sum=0;
            TExist=false;
            for (in=1;in<=4;in++)
            {
                if (table[in][j]==0)
                {
                    TExist=true;
                }
                sum=sum+table[in][j];
            }

            if (sum==-4 || (sum==-3 && TExist))
            {
                foundwinner=2;
                break;
            }
            if (sum==4 || (sum==3 && TExist))
            {
                foundwinner=1;
                break;
            }
        }
        ///////////////////////////////////////////////////////////////
        if (foundwinner!=0)
        {
            if (foundwinner==1)
            {
                printf("Case #%lld: X won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }
            if (foundwinner==2)
            {
                printf("Case #%lld: O won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }

            continue;
        }
        ///////////////////////////////////////////////////////////////
        sum=table[1][1]+table[2][2]+table[3][3]+table[4][4];

        if (table[1][1]==0 || table[2][2]==0 || table[3][3]==0 || table[4][4]==0)
        TExist=true;
        else
        TExist=false;

        if (sum==-4 || (sum==-3 && TExist))
        {
            foundwinner=2;
        }
        if (sum==4 || (sum==3 && TExist))
        {
            foundwinner=1;
        }
        ///////////////////////////////////////////////
        if (foundwinner!=0)
        {
            if (foundwinner==1)
            {
                printf("Case #%lld: X won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }
            if (foundwinner==2)
            {
                printf("Case #%lld: O won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }

            continue;
        }
        ////////////////////////////////////////////
        sum=table[1][4]+table[2][3]+table[3][2]+table[4][1];

        if (table[1][4]==0 || table[2][3]==0 || table[3][2]==0 || table[4][1]==0)
        TExist=true;
        else
        TExist=false;

        if (sum==-4 || (sum==-3 && TExist))
        {
            foundwinner=2;
        }
        if (sum==4 || (sum==3 && TExist))
        {
            foundwinner=1;
        }
        ///////////////////////////////////////////////
        if (foundwinner!=0)
        {
            if (foundwinner==1)
            {
                printf("Case #%lld: X won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }
            if (foundwinner==2)
            {
                printf("Case #%lld: O won",i);
                if (i!=n)
                {
                    printf("\n");
                }
            }

            continue;
        }
        //////////////////////////////////////////////

        blocked=true;

        for (j=1;j<=4;j++)
        {
            for (in=1;in<=4;in++)
            {
                if (table[j][in]==999)
                {
                    blocked=false;
                }
            }
        }

        if (blocked)
        {
            printf("Case #%lld: Draw",i);
            if (i!=n)
            {
                printf("\n");
            }
        }
        else
        {
            printf("Case #%lld: Game has not completed",i);
            if (i!=n)
            {
                printf("\n");
            }
        }
    }

    return 0;
}
