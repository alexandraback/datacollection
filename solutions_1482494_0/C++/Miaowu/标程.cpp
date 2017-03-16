#include <stdio.h>

int vis[15][2];
int yes[15][2];
int n;
int ans,tag;

void DFS(int t,int num)
{
    if (num>=ans) return;
    if (tag==1) return;
    int i,j,ok=0;
    for (i=0;i<n;i++)
    {
        if (vis[i][1]==0) break;
    }
    if (i==n)
    {
        ans=num;
        return;
    }
    for (i=0;i<n;i++)
    {
        if (yes[i][1]<=t && vis[i][1]==0)
        {
            ok=1;
            vis[i][1]=1;
            DFS(t+2-vis[i][0],num+1);
            vis[i][1]=0;
        }
    }
    if (ok==1) return;
    for (i=0;i<n;i++)
    {
        if (yes[i][0]<=t && vis[i][1]==0 && vis[i][0]==0)
        {
            ok=1;
            vis[i][0]=1;
            DFS(t+1,num+1);
            vis[i][0]=0;
        }
    }
    if (ok==1) return;
    tag=1;
    return;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int i,j,T,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&yes[i][0],&yes[i][1]);
        }
        ans=99999;
        tag=0;
        DFS(0,0);
        if (ans==99999) printf("Case #%d: Too Bad\n",cnt++);
        else printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;
}
