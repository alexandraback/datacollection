#include <cstdio>
#include <cstring>

#define MAXN 12

int n,ans;
int a[MAXN];
bool used[MAXN];

void dfs(int curx,int cury,int x,int y,int step)
{
    if (x==0 || x==cury)
        if (y==0 || y==curx)
            if (step>ans) ans=step;

    // left
    if (x==0)
    {
        for (int i=1;i<=n;i++)
            if (!used[i])
            {
                used[i]=true;
                if (a[i]==curx)
                    dfs(i,cury,0,y,step+1);
                else
                    dfs(i,cury,a[i],y,step+1);
                used[i]=false;
            }
    }
    else if (!used[x])
    {
        used[x]=true;
        if (a[x]==curx)
        {
            if (step!=1)
                dfs(x,cury,0,y,step+1);
            else
                dfs(x,cury,0,0,step+1);
        }
        else
        {
            if (step!=1)
                dfs(x,cury,a[x],y,step+1);
            else
                dfs(x,cury,a[x],0,step+1);
        }
        used[x]=false;
    }

    // right
    if (y==0)
    {
        for (int i=1;i<=n;i++)
            if (!used[i])
            {
                used[i]=true;
                if (a[i]==cury)
                    dfs(curx,i,x,0,step+1);
                else
                    dfs(curx,i,x,a[i],step+1);
                used[i]=false;
            }
    }
    else if (!used[y])
    {
        used[y]=true;
        if (a[y]==cury)
        {
            if (step!=1)
                dfs(curx,y,x,0,step+1);
            else
                dfs(curx,y,0,0,step+1);
        }
        else
        {
            if (step!=1)
                dfs(curx,y,x,a[y],step+1);
            else
                dfs(curx,y,0,a[y],step+1);
        }
        used[y]=false;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i]=x;
        }
        memset(used,false,sizeof(used));
        ans = 0;
        for (int i=1;i<=n;i++)
        {
            used[i]=true;
            dfs(i,i,a[i],a[i],1);
            used[i]=false;
        }
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;
}
