#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define mod 1000000007LL
#define pii pair<int,int>
#define pll pair<ll,ll>
int dp[1000011];
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,ans,l,n,m,t,c=1,a[100001];
    dp[1]=1;
    for(i=2;i<=1000000;i++)
    {
        j=i;
        k=0;
        if(i%10==0)
        {
            dp[i]=min(i,dp[i-1]+1);
            continue;
        }
        dp[i]=dp[i-1]+1;
        while(j>0)
        {
            k=(k*10)+(j%10);
            j=j/10;
        }
        if(k>=i)
            dp[i]=min(i,dp[i]);
        else
            dp[i]=min(dp[k]+1,min(i,dp[i]));
    }
//    for(i=1;i<=23;i++)
//        printf("i=%d\n",dp[i] );
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--)
    {
        scanf("%d",&n);
        //printf("%d",n);
//        for(i=0;i<n;i++)
//            scanf("%d",&a[i]);
        //for(i=0;i<n;i++)
        //    printf("%d ",a[i]);
        //printf("\n");
        ans=0;


        assert(n<=1000000);
        ans=dp[n];
        printf("Case #%d: %d\n",c,ans);
        c++;
    }
    return 0;
}

