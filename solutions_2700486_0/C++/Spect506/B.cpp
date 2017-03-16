#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,x,y,sum[2900];
double f[800][800];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt,test,i,j;
    scanf("%d",&test);
    sum[1]=1;
    sum[0]=1;
    for(n=2;;n++)
    {
      sum[0]+=4;
      sum[n]=sum[n-1]+sum[0];
      if(sum[n]>1000000)break;
    }
    sum[0]=n-1;
    for(tt=1;tt<=test;tt++)
    {
                           if(tt==6)
                           printf("");
      scanf("%d%d%d",&n,&x,&y);
      printf("Case #%d: ",tt);
      for(i=1;i<=sum[0];i++)if(n<=sum[i])break;
      if((x+y>>1)+1>i)
      {
        printf("0\n");
        continue;
      }
      if((x+y>>1)+1<i)
      {
        printf("1\n");
        continue;
      }
      x=-x;
      if(x==0)
      {
        if(n==sum[i])printf("1\n");
        else printf("0\n");
        continue;
      }//总共 n-sum[i-1]个 至少要放y/2+1个 最多(sum[i]-sum[i-1])/2个
      int zonggong=n-sum[i-1],zhishao=y+1,zuiduo=sum[i]-sum[i-1]>>1;
      f[0][0]=1;
      for(i=1;i<=zonggong;i++)
      {
                              if(i==3)
                              printf("");
        for(j=0;j<=zuiduo&&j<=i;j++)
        {
          if(j==0)
          {
            if(i-j>zuiduo)j=i-zuiduo;
          }
          if(j==i-zuiduo)f[i][j]=f[i-1][j-1];
          else if(j==zuiduo)f[i][j]=f[i-1][j];
          else f[i][j]=f[i-1][j]*0.5+f[i-1][j-1]*0.5;
        }
      }
      double ans=0;
      for(i=zhishao;i<=zuiduo;i++)ans+=f[zonggong][i];
      printf("%.10lf\n",ans);
    }
    return 0;
}
