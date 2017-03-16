#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll a[105];

int main()
{
    freopen("3inp.in","r",stdin);
    freopen("3out.txt","w",stdout);
    int t,i,T,d,ans;
    ll v,sum,c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld%d%lld",&c,&d,&v);
        for(i=0;i<100;i++)  a[i]=0;
        for(i=0;i<d;i++)
        {
            scanf("%lld",&a[i]);
        }
        sum=0LL;
        ans=0;
        for(i=0;i<d&&sum<v;)
        {
            if(sum+1LL<a[i])
            {
                ans++;
                sum += c*(sum+1LL);
            }
            else
            {
                sum=sum+c*a[i];
                i++;
            }
        }
        if(sum>=v)
            printf("Case #%d: %d\n",t,ans);
        else
        {
            while(sum<v)
            {
                sum += c*(sum+1LL);
                ans++;
            }
            printf("Case #%d: %d\n",t,ans);
        }
    }
    return 0;
}


