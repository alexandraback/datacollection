#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int t;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output_small.txt","w",stdout);

    Int i,j;
    Int test;
    Int a,b,k;
    Int c;
    Int ctr;

    scanf("%lld",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%lld %lld %lld",&a,&b,&k);

        ctr=0;

        for (i=0;i<a;i++)
        {
            for (j=0;j<b;j++)
            {
                c=i&j;

                if (c<k)
                {
                    ctr++;
                }
            }
        }

        printf("Case #%lld: %lld\n",test,ctr);
    }

    return 0;
}
