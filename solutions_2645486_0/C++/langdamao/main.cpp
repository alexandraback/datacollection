#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
int n,r,e;
int dp[100][100];
int v[100];
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T,ca=1;
    scanf("%d",&T);
    while (T--){
       scanf("%d%d%d",&e,&r,&n);
       for (int i=1;i<=n;i++){
         scanf("%d",&v[i]);
       }
       memset(dp,0,sizeof(dp));
       for (int j=0;j<=e;j++) dp[1][j]=(e-j)*v[1];
       for (int i=2;i<=n;i++){
         for (int j=0;j<=e;j++){
             dp[i][j]=0;
            int st=max(r-j,0);int se=min(e,e-j+r);
            se=min(e-j,se);
            for (int k=st;k<=se;k++){
               dp[i][j]=max(dp[i-1][j-r+k]+k*v[i],dp[i][j]);
            }
            //cout <<i<<' '<<j<<" "<<dp[i][j]<<endl;
         }
       }
       int ans=0;
       for (int i=0;i<=e;i++) if (dp[n][i]>ans) ans=dp[n][i];
       printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
