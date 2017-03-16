

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector <int> a[1005];
int vis[1005];
int ava[1005];
int up;
int ok,n;

void DFS(int t)
{
    int i,j;
    if (ok==1) return;
    if (vis[t]==1)
    {
        ok=1;
        return;
    }
    vis[t]=1;
    for (i=0;i<a[t].size();i++)
    {
        DFS(a[t][i]);
    }
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,T,m,x,up,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        up=0;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            a[i].clear();
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&m);
            if (m==0)
            {
                ava[up++]=i;
            }
            while(m--)
            {
                scanf("%d",&x);
                x--;
                a[x].push_back(i);
            }
        }
        ok=0;
        for (i=0;i<up;i++)
        {
            memset(vis,0,sizeof(vis));
            DFS(ava[i]);
            if (ok==1) break;
        }
        printf("Case #%d: ",cnt++);
        if (ok==1)
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}



