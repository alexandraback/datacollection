#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int dp[200][100];
int a[200];
void update(int & a,int b)
{
    a=max(a,b);
}
int main()
{
    freopen("2.in","r",stdin);
    freopen("21.out","w",stdout);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        int e,r,n;
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<=e;j++){
                for(int k=0;k<=j;k++){
                    update(dp[i+1][min(e,j-k+r)],dp[i][j]+k*a[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=e;i++) ans=max(ans,dp[n][i]);
        printf("Case #%d: %d\n",++ca,ans);
    }
}
