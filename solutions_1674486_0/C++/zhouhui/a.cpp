#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[10004][10004],n,fg,vist[10004];
void dfs(int x)
{
   for(int i=1;i<=n;i++)
   if(g[x][i]&&vist[i]==0)
   {
       vist[i]=1;
       dfs(i);
   }
   else if(g[x][i]&&vist[i])
   {
       fg=1;
   }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        for(int i=1; i<=n; i++)
        {
            int m,a;
            scanf("%d",&m);
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a);
                g[i][a]=1;
            }
        }
        fg=0;
        for(int i=1; i<=n; i++)
           {
               memset(vist,0,sizeof(vist));
               dfs(i);
               if(fg)
               break;
           }
        if(fg)
            printf("Case #%d: Yes\n",k);
        else
            printf("Case #%d: No\n",k);
    }
    return 0;
}
