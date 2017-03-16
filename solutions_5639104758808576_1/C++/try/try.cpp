#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int c,t,i,n,num,sum,ans;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d",&n);
        sum=0;
        ans=0;
        for(i=0;i<=n;i++)
        {
            scanf("%1d",&num);
            if(sum<i)
            {
                ans=ans+i-sum;
                sum=num+i;
            }
            else
            {
                sum=sum+num;
            }
        }
        printf("Case #%d: %d\n",c+1,ans);
    }
    return 0;
}
