#include<stdio.h>
#include<string.h>
int n,lj[1001][1001],ds[1001],hash[1001];
void search(int now)
{
     int i;
     hash[now]++;
     if(hash[now]>1)return;
     for(i=1;i<=lj[now][0];i++)search(lj[now][i]);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,qq,test;
    bool solve;
    scanf("%d",&test);
    for(qq=1;qq<=test;qq++)
    {
      solve=0;
      scanf("%d",&n);
      memset(ds,0,sizeof(ds));
      for(i=1;i<=n;i++)
      {
        scanf("%d",&lj[i][0]);
        for(j=1;j<=lj[i][0];j++)
        {
          scanf("%d",&lj[i][j]);
          ds[lj[i][j]]=1;
        }
      }
      for(i=1;i<=n;i++)
        if(ds[i]==0)
        {
          memset(hash,0,sizeof(hash));
          search(i);
          for(j=1;j<=n;j++)
            if(hash[j]>1)
            {
              solve=1;
              break;
            }
          if(solve)break;
        }
      if(solve)printf("Case #%d: Yes\n",qq);
      else printf("Case #%d: No\n",qq);
    }
    return 0;
}
