#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define  ll unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
ll f[51];
int vis[51],a[51][51],n;
void dfs(int x,ll m,int t)
{
  //  cout<<x<<" "<<m<<" "<<t<<endl;
    if(m==0) return;
    a[x][n]=1;
    m--;
    for(int i=1;i<n;i++)
    {//cout<<i<<endl;
        if(vis[i]) continue;
        if(m==0) return;
        vis[i]=1;
        a[x][i]=1;
        dfs(i,min(f[t-1],m),t-1);
        m=m-min(f[t-1],m);
        vis[i]=0;
    }
    return;
}
int main()
{
   //  freopen("Binput.txt","r",stdin);
  //  freopen("Boutput.txt","w",stdout);
   f[2]=1;f[3]=2;
   for(int i=2;i<22;i++)f[i+2]=f[i-1+2]*i+1;
   int t,cas=1,sum;
   scanf("%d",&t);
   ll m;
   while(t--)
   {
       scanf("%d%lld",&n,&m);
       printf("Case #%d: ",cas++);
       if(m<22&&m>f[n])
       {
           printf("IMPOSSIBLE\n");
           continue;
       }
       printf("POSSIBLE\n");
       memset(vis,0,sizeof(vis));
       vis[1]=1;
       dfs(1,m,n);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++) cout<<a[i][j];cout<<endl;
       }
   }
   return 0;
}
