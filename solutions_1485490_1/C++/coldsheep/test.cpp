#include <iostream>
#include <vector>
using namespace std;
long long dp[105][105];
long long suma[105][105],sumb[105][105];
struct node
{
long long t,v;
}a[105],b[105];
long long maxx(long long a,long long b)
{
return a>b?a:b;
}
long long minn(long long a,long long b)
{
return a<b?a:b;
}
int main()
{
freopen("C-large.in","r",stdin);
freopen("out.out","w",stdout);
int i,j,k,t,n,m,co=1,x,y;
scanf("%d",&t);
while(t--)
{
memset(suma,0,sizeof(suma));
memset(sumb,0,sizeof(sumb));
scanf("%d%d",&n,&m);
for (i=0;i<n;i++)
{
scanf("%lld%lld",&a[i].v,&a[i].t);
suma[a[i].t][i+1]=a[i].v;
}
for (i=0;i<n;i++)
for (k=0;k<=100;k++)
suma[k][i+1]+=suma[k][i];
for (i=0;i<m;i++)
{
scanf("%lld%lld",&b[i].v,&b[i].t);
sumb[b[i].t][i+1]=b[i].v;
}
for (i=0;i<m;i++)
for (k=0;k<=100;k++)
sumb[k][i+1]+=sumb[k][i];
memset(dp,0,sizeof(dp));

for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
{
if (a[i-1].t!=b[j-1].t)
{
dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
}
else
{
for (x=0;x<i;x++)
for (y=0;y<j;y++)
dp[i][j]=maxx(dp[i][j],dp[x][y]+minn(suma[a[i-1].t][i]-suma[a[i-1].t][x],sumb[b[j-1].t][j]-sumb[b[j-1].t][y]));
}
}

long long ans=0;
for (i=0;i<=n;i++)
for (j=0;j<=m;j++)
ans=maxx(ans,dp[i][j]);
printf("Case #%d: %lld\n",co++,ans);
}
return 0;
}

