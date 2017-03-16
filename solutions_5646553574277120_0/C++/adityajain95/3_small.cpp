#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int a[105];

int main()
{
    freopen("3inp.in","r",stdin);
    freopen("3out.txt","w",stdout);
    int t,i,T,c,d,v,sum,ans;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&c,&d,&v);
        for(i=0;i<100;i++)  a[i]=0;
        for(i=0;i<d;i++)
        {
            scanf("%d",&a[i]);
        }
        sum=0;
        ans=0;
        for(i=0;i<d;)
        {
            if(sum+1<a[i])
            {
                ans++;
                sum=sum+sum+1;
            }
            else
            {
                sum=sum+a[i];
                i++;
            }
        }
        if(sum>=v)
            printf("Case #%d: %d\n",t,ans);
        else
        {
            while(sum<v)
            {
                sum=sum+sum+1;
                ans++;
            }
            printf("Case #%d: %d\n",t,ans);
        }
    }
    return 0;
}


