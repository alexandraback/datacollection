#include<cstdio>

int arr[100],dp[100][100];

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int t,e,r,n;
    scanf("%d",&t);
    int cas=1;
    while(t--) {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<100;i++) {
             for(int j=0;j<100;j++) dp[i][j]=-1;
        }
        dp[0][e]=0;
        for(int i=0;i<n;i++) {
             for(int j=0;j<=e;j++) {
                  if(dp[i][j]>=0) {
                       for(int k=0;k<=j;k++) {
                           dp[i+1][j-k+r]=max(dp[i+1][j-k+r],dp[i][j]+arr[i+1]*k);
                       }
                  }
             }
        }
        int ans=0;
        for(int i=0;i<100;i++) {
             for(int j=0;j<100;j++) if(dp[i][j]>ans) ans=dp[i][j];
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
