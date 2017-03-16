#include<stdio.h>
#include<string.h>
int n,m,type[2][101];
long long f[101][101],a[101],b[101],ans,stk[101],last[2][101],mmax[101][101];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test,qq,i,j,i1,j1,k,l;
    long long tmp1,tmp2,maxlast;
    scanf("%d",&test);
    for(qq=1;qq<=test;qq++)
    {
      scanf("%d%d",&n,&m);
      ans=0;
      memset(f,0,sizeof(f));
      memset(last,0,sizeof(last));
      memset(stk,0,sizeof(stk));
      for(i=1;i<=n;i++)
      {
        scanf("%I64d%d",&a[i],&type[0][i]);
        last[0][i]=stk[type[0][i]];
        stk[type[0][i]]=i;
      }
      memset(stk,0,sizeof(stk));
      for(i=1;i<=m;i++)
      {
        scanf("%I64d%d",&b[i],&type[1][i]);
        last[1][i]=stk[type[1][i]];
        stk[type[1][i]]=i;
      }
      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
          if(type[0][i]!=type[1][j])continue;
          tmp1=0;
          for(i1=i;i1;i1=last[0][i1])
          {
            tmp1+=a[i1];
            tmp2=0;
            for(j1=j;j1;j1=last[1][j1])
            {
              tmp2+=b[j1];
              maxlast=0;
              /*for(k=1;k<i1;k++)
                for(l=1;l<j1;l++)
                  if(f[k][l]>maxlast)maxlast=f[k][l];*/
              maxlast=mmax[i1-1][j1-1];
              if(tmp1>tmp2)maxlast+=tmp2;
              else maxlast+=tmp1;
              if(maxlast>f[i][j])f[i][j]=maxlast;
            }
          }
          if(f[i][j]>ans)ans=f[i][j];
          for(k=i;k<=n;k++)for(l=j;l<=n;l++)if(f[i][j]>mmax[i][j])mmax[i][j]=f[i][j];
        }
      printf("Case #%d: %I64d\n",qq,ans);
    }
    return 0;
}
