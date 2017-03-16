#include <vector> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <string.h>
#include<map> 
using namespace std;
double value[2][1111];
int n,ans[2],dp[1001][1001];
bool vis[1001];
int dfs(int l,int r)
{
    int id;
    if(l>r)
       return 0;
    if(dp[l][r]>=0)
        return dp[l][r];
    id=n-1-(r-l);
    //printf("id=%d\n",id);
    if(value[0][id]>value[1][l])
        dp[l][r]=dfs(l+1,r)+1;
    else
        dp[l][r]=dfs(l+1,r);
    int now;
    if(value[0][id]<value[1][r])
        now=dfs(l,r-1);
    else
        now=dfs(l,r-1)+1;
    if(dp[l][r]<0||dp[l][r]<now)
       dp[l][r]=now;
    return dp[l][r];
}
int main()
{
    int t,i,j,s,p,q,tst=0;
     freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        tst++;
        scanf("%d",&n);
        for(i=0;i<2;i++)
           for(j=0;j<n;j++)
               scanf("%lf",&value[i][j]);
        sort(value[0],value[0]+n);
        sort(value[1],value[1]+n);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: ",tst);
        printf("%d ",dfs(0,n-1));
        memset(vis,false,sizeof(vis));
        ans[1]=0;
        for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
           {
               if(!vis[j]&&value[1][j]>value[0][i])
                   break;
           }
           if(j>=n)
              ans[1]++;
           else
              vis[j]=true;
        }
        printf("%d\n",ans[1]);
    }
    return 0;
}
