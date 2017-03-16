#include<cstdio>
#include<cstring>
int a[25][25],n,m,k,t,T,s,ss,ans;
bool v[25][25],bj;
void dfs(int x,int y)
{
     if (a[x][y]||v[x][y])return;
     if (x<1||x>n)return;
     if (y<1||y>m)return;
     if (x==1||x==n)bj=0;
     if (y==1||y==m)bj=0;
     ss++;
     v[x][y]=1;
     dfs(x+1,y);
     dfs(x,y+1);
     dfs(x-1,y);
     dfs(x,y-1);
 }
bool check()
{
     s=ss=0;
     for (int i=1;i<=n;i++)
       for (int j=1;j<=m;j++)
         if (!v[i][j])
           if (a[i][j])s++;
           else
           {
               bj=1;
               ss=0;
               dfs(i,j);
               if (bj)s+=ss;
           }
     for (int i=1;i<=n;i++)memset(v[i],0,sizeof(bool)*(m+5));
     return s>=k;
 }
void work(int x,int y,int s)
{
     if (s>=ans)return;
     if (x==n&&y>m)
     {
         if (check())ans=s;
         return;
     }
     if (y>m)return work(x+1,1,s);
     a[x][y]=1;
     work(x,y+1,s+1);
     a[x][y]=0;
     work(x,y+1,s);
 }
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%d%d%d",&n,&m,&k);
        ans=~0U>>1;
        work(1,1,0);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
