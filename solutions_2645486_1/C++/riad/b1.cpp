#include <stdio.h>
#include <algorithm>
#define MAX 100005

typedef long long ll;

using namespace std;

ll max1[MAX],inp[MAX],tot[MAX];

void init(ll node,ll b,ll e)
{
    if (b==e)
    {
        max1[node]=inp[b];
        return ;
    }
    init(2*node,b,(b+e)/2);
    init(2*node+1,(b+e)/2+1,e);
    max1[node]=max(max1[2*node],max1[2*node+1]);
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if (e<i||b>j) return -1;
    if (b>=i&&e<=j) return max1[node];
    return max(query(2*node,b,(b+e)/2,i,j),query(2*node+1,(b+e)/2+1,e,i,j));
}

int main()
{
    freopen("bin1.txt","r",stdin);
    freopen("bout1.txt","w",stdout);
    ll test,cas,e,r,n,i,left,sum,ans,j,p;
    scanf("%lld",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%lld%lld%lld",&e,&r,&n);
        for (i=0;i<n;i++) scanf("%lld",&inp[i]);
        init(1,0,n-1);
        left=0;
        tot[0]=e;
        sum=e;
        ans=0;
        for (i=0;i<n;i++)
        {
            for (j=left;j<=i&&sum>e-r;j++)
            {
                p=min(tot[j],sum-e+r);
                ans+=query(1,0,n-1,j,i)*p;
                tot[j]-=p;
                sum-=p;
            }
            while (left<=i&&!tot[left]) left++;
            if (i<n-1)
            {
                tot[i+1]=r;
                sum=min(sum+r,e);
            }
        }
        for (j=left;j<n&&sum>0;j++)
        {
            p=min(tot[j],sum);
            ans+=query(1,0,n-1,j,n)*p;
            tot[j]-=p;
            sum-=p;
        }
        printf("Case #%lld: %lld\n",cas,ans);
    }
    return 0;
}
