#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int lawn[101][101];

int main()
{
    Int i,j,in,ja;
    Int tests;
    Int n,m;
    Int bads;

    scanf("%lld",&tests);

    for (i=1;i<=tests;i++)
    {
        scanf("%lld %lld",&n,&m);

        for (j=1;j<=n;j++)
        {
            for (in=1;in<=m;in++)
            {
                scanf("%lld",&lawn[j][in]);
            }
        }

        for (j=1;j<=n;j++)
        {
            for (in=1;in<=m;in++)
            {
                ///Fixing [j,in]
                bads=0;
                for (ja=1;ja<=n;ja++)
                {
                    if (lawn[ja][in]>lawn[j][in])
                    {
                        bads++;
                        break;
                    }
                }

                for (ja=1;ja<=m;ja++)
                {
                    if (lawn[j][ja]>lawn[j][in])
                    {
                        bads++;
                        break;
                    }
                }

                if (bads==2)
                {
                    break;
                }
            }

            if (bads==2)
            {
                break;
            }
        }

        if (bads==2)
        {
            printf("Case #%lld: NO\n",i);
        }
        else
        {
            printf("Case #%lld: YES\n",i);
        }
    }

    return 0;
}
