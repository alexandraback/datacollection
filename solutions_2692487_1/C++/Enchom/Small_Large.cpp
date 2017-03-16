#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int motes[101];
Int AMote;
Int n;

int main()
{
    Int t;
    Int i,j;
    Int bestans;
    Int actionsdone;
    Int x,answer;

    scanf("%lld",&t);

    for (i=1;i<=t;i++)
    {
        scanf("%lld %lld",&AMote,&n);

        bestans=n;
        actionsdone=0;

        for (j=1;j<=n;j++)
        {
            scanf("%lld",&motes[j]);
        }

        if (AMote==1)
        {
            printf("Case #%lld: %lld\n",i,n);
            continue;
        }

        sort(motes+1,motes+1+n);

        for (j=1;j<=n;j++)
        {
            if (motes[j]<AMote)
            {
                AMote=AMote+motes[j];
            }
            else ///Check for answer
            {
                answer=actionsdone+n-j+1;

                if (answer<bestans)
                {
                    bestans=answer;
                }

                while(AMote<=motes[j])
                {
                    actionsdone++;
                    AMote=2*AMote-1;
                }
                AMote=AMote+motes[j];
            }
        }

        if (actionsdone<bestans)
        {
            bestans=actionsdone;
        }

        printf("Case #%lld: %lld\n",i,bestans);
    }

    return 0;
}
