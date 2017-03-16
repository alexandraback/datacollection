#include "stdio.h"
#include "algorithm"
using namespace std;
int a[5000];
main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("1B_S0.txt","w",stdout);
    int t,cs;
    int n,i,same;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        for(i=0;i<2*n*n-n;i++)
            scanf("%d",&a[i]);
        sort(a,a+2*n*n-n);
        same=1;
        printf("Case #%d:",cs);
        for(i=1;i<2*n*n-n;i++)
        {
            if(a[i]==a[i-1])
                same++;
            else if(same%2==1)
            {
                printf(" %d",a[i-1]);
                same=1;
            }
            else same=1;
        }
        if(same%2==1)
            printf(" %d",a[2*n*n-n-1]);
        printf("\n");
    }
}
