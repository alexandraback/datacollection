#include<cstdio>
int n,m,a[101][101];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt,test,i,j,i1,j1;
    bool no,tmp;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          scanf("%d",&a[i][j]);
      no=0;
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
        {
          for(i1=1;i1<=n;i1++)if(a[i1][j]>a[i][j])break;
          if(i1>n)continue;
          for(j1=1;j1<=m;j1++)if(a[i][j1]>a[i][j])break;
          if(j1>m)continue;
          no=1;
          break;
        }
        if(no)break;
      }
      if(no)printf("Case #%d: NO\n",tt);
      else printf("Case #%d: YES\n",tt);
    }
    return 0;
}
