#include <stdio.h>

int arr[23],last[2000003];

int main()
{
    freopen("c.txt","r",stdin);
    freopen("c.out","w",stdout);
    int test,cas,n,i,sum,j,a,b;
    bool sp;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",&arr[i]);
        for (i=1;i<=2000000;i++) last[i]=-1;
        for (i=1;i<(1<<n);i++)
        {
            sum=0;
            for (j=0;j<n;j++)
            {
                if (i&(1<<j)) sum+=arr[j];
            }
            if (last[sum]!=-1)
            {
                a=last[sum];
                b=i;
                break;
            }
            last[sum]=i;
        }
        printf("Case #%d:\n",cas);
        sp=0;
        for (i=0;i<n;i++)
        {
            if (a&(1<<i))
            {
                if (!sp) sp=1;
                else printf(" ");
                printf("%d",arr[i]);
            }
        }
        printf("\n");
        sp=0;
        for (i=0;i<n;i++)
        {
            if (b&(1<<i))
            {
                if (!sp) sp=1;
                else printf(" ");
                printf("%d",arr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
