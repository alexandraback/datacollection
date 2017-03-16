#include<stdio.h>
int main()
{
    long long c,d,v,t,i,a[200],j,curMax,cnt,curr;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        curMax=0;
        cnt=0;
        scanf("%lld%lld%lld",&c,&d,&v);
        for(j=0;j<d;j++)
        {
            scanf("%lld",&a[j]);
        }

        j=0;
        while(curMax<v)
        {
            if(j>=d || a[j]>(curMax+1))
            {
                cnt++;
                curr=curMax+1;
                curMax=(curMax+c*curr);
            }
            else
            {
                curMax=(curMax+c*a[j]);
                j++;
            }
        }
        printf("Case #%lld: %lld\n",i,cnt);
    }
}
