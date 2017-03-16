#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[110][110];
int n,s;
int a[110];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int ca,cc=0;
    int i,j,sum,t;
    scanf("%d",&ca);
    while (ca--){
          memset(dp,0,sizeof(dp));
          scanf("%d%d",&s,&n);
          for (i=1;i<=n;i++) scanf("%d",&a[i]);
          sort(a+1,a+1+n);
          dp[0][0]=s;
          for (i=0;i<n;i++){
              for (j=0;j<=n;j++){
                  if (dp[i][j]>0){
                     if (dp[i][j]>1000000) dp[i][j]=1000001;
                     dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);   
                     sum=0;t=dp[i][j];
                     if (t>1){
                        while (t<=a[i+1]){
                              t=t*2-1;
                              sum++;                             
                        }
                        if (j+sum<=n) dp[i+1][j+sum]=max(dp[i+1][j+sum],t+a[i+1]);   
                     }
                  }
              }
          }
          for (i=0;i<=n;i++)
              if (dp[n][i]>0) break;
          printf("Case #%d: %d\n",++cc,i);
    }
    return 0;
}
          
