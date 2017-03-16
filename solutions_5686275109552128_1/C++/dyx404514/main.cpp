#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define maxn 1010
int dp[1010][1010];
int a[maxn];
using namespace std;

int dfs(int x,int y){
    if(y>=x)
    return 0;
    if(y>x/2) return dp[x][y]=1;
    if(dp[x][y]!=-1)return dp[x][y];
    int mi=1010;
    int limit=x/2;
    for(int i=y;i<x;i++){
        mi=min(mi,1+dfs(i,y)+dfs(x-i,y));
    }
    return dp[x][y]=mi;
}
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    for(int i=0;i<1000;i++)
    memset(dp,-1,sizeof(dp));
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int ans=a[n-1];
        for(int i=1;i<=a[n-1];i++){
            int sum=0;
            for(int j=n-1;j>=0;j--){
                if(a[j]<=i)
                break;
                sum+=dfs(a[j],i);
            }
            ans=min(ans,i+sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
