#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
typedef long long int LL;
const int MAXN=256;
LL toy[MAXN],Ctoy[MAXN];
LL f[MAXN][MAXN],maps[MAXN][MAXN],maps2[MAXN][MAXN];
LL box[MAXN],Cbox[MAXN];
LL ans;
LL max(LL toy,LL box)
{
	if(toy>box)
	return toy;
	return box;
}
LL min(LL toy,LL box)
{
	if(toy<box)
	return toy;
	return box;
}
int n,m,ty;
void solve() 
{
  int i,j,k,t,typ;
  for (i=1;i<=n;i++)
  for (j=1;j<=m;j++) 
  for (k=1;k<=i;k++)
  for (t=1;t<=j;t++)
  for (typ=1;typ<=ty;typ++)
  f[i][j]=max((LL)f[i][j],(LL)f[i-k][j-t]+min(maps[typ][i]-maps[typ][i-k],maps2[typ][j]-maps2[typ][j-t]));
    
}

int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int T,t;
  scanf("%d",&T);
  for(t=1;t<=T;t++) 
  {
	int i,j;
    scanf("%d%d",&n,&m),ty=0;
    for(i=1;i<=n;i++) 
	{
      scanf("%I64d%I64d",&toy[i],&Ctoy[i]);
      if (ty<Ctoy[i]) ty=Ctoy[i];
      for(j=0;j<=100;j++)
       maps[j][i]=maps[j][i-1];
      maps[Ctoy[i]][i]+=toy[i];
    }
    for(i=1;i<=m;i++) 
	{
      scanf("%I64d%I64d",&box[i],&Cbox[i]);
      if(ty<Cbox[i]) ty=Cbox[i];
      for(j=0;j<=100;j++)
        maps2[j][i]=maps2[j][i-1];
      maps2[Cbox[i]][i]+=box[i];
    }
    for(i=0;i<=n;i++)
    for(j=0;j<=m;j++)
    f[i][j]=0;
    solve();
    ans=f[n][m];
    printf("Case #%d: %I64d\n",t,ans);
  }
}
