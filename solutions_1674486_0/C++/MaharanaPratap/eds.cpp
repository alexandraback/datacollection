//ultrablue/rjpt
#include<queue>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<cstring>
using namespace std;
#define tr(ds,it) for(typeof(ds.end()) it=ds.begin();it!=ds.end();it++)
int t;
bool dfs(int g[1001][11],int j,bool dn[1001])
{
  dn[j]=true;
  for(int i=1;i<=g[j][0];i++)
  {
    if(dn[g[j][i]])
    {
      return true;
    }
    if(dfs(g,g[j][i],dn))
    {
      return true;
    }
  }
  return false;
}
int main(int argc,char* argv[])
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&t);
  for(int i=1;i<=t;i++)
  {
    int n;
    scanf("%d",&n);
    int g[1001][11];
    for(int j=1;j<=n;j++)
    {
      scanf("%d",&g[j][0]);
      for(int k=1;k<=g[j][0];k++)
      {
        scanf("%d",&g[j][k]);
      }
    }
    bool dn[1001],flg=false;
    for(int j=1;j<=n;j++)
    {
      memset (dn,0,sizeof(dn));
      flg= dfs(g,j,dn);
      if(flg)
      {
        break;
      }
    }
    /*//////////////////
    cout<<n<<endl;
    for(int j=1;j<=n;j++)
    {
      for(int k=0;k<=g[j][0];k++)
      {
        cout<<g[j][k]<<"   ";
      }
      cout<<endl;
    }
    */////////////////////
    printf("Case #%d: %s\n",i,flg?"Yes":"No");
  }
  //system("pause");
  return 0;
}
