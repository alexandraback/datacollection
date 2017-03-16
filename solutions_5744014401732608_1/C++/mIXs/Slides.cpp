#include<cstdio>
using namespace std;
main()
{
    long long int rev,ans;
    int n,i,j,k,q,nq;
    scanf("%d",&nq);
    for(q=1;q<=nq;q++)
    {
        scanf("%d%lld",&n,&ans);
        if(ans<=((long long int)1<<(n-2)))
        {
            printf("Case #%d: POSSIBLE\n",q);
            if(ans==((long long int)1<<(n-2)))
            {
                printf("0");
                for(i=1;i<n;i++)
                {
                    printf("1");
                }
                printf("\n");
            }
            else
            {
                rev=0;
                for(i=0;i<n-2;i++)
                {
                    rev|=(ans&1);
                    rev<<=1;
                    ans>>=1;
                }
                for(i=0;i<n;i++)
                {
                    printf("%d",rev&1);
                    rev>>=1;
                }
                printf("\n");
            }
            for(i=1;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(j<=i)
                        printf("0");
                    else
                        printf("1");
                }
                printf("\n");
            }
        }
        else
            printf("Case #%d: IMPOSSIBLE\n",q);
    }
    return 0;
}
