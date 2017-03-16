#include <iostream>
#include <stdio.h>
using namespace std;

int T;
int n;
int a[1011];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large-output.txt","w",stdout);

    int test;
    int i,j;
    int excess,specials;
    int best;

    scanf("%d",&T);

    for (test=1;test<=T;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

        best=999999;
        for (i=1000;i>=1;i--)
        {
            specials=0;
            for (j=1;j<=n;j++)
            {
                excess=a[j]-i;

                if (excess>0)
                {
                    specials+=(excess-1)/i+1;
                }
            }

            if (i+specials<best)
            {
                best=i+specials;
            }
        }

        printf("Case #%d: %d\n",test,best);
    }
}
