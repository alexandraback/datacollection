#include<stdio.h>
#define max(a,b) (a>b?a:b)
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.c","r",stdin);
        freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE
    int t,l;
    scanf("%d",&t);
    for(l=1;l<=t;l++)
    {
        int a,b,k;
        int i,j;
        int array[1001]={0};
        scanf("%d%d%d",&a,&b,&k);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                array[i&j]++;
            }
        }
        long long sum=0;
        for(i=0;i<k;i++)
        {
            if(array[i]!=0)
                sum=sum+array[i];
        }

        printf("Case #%d: %d\n",l,sum);

    }
    return 0;
}
/*

*/
