#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
bool a[10][10];
char v[10][10];
int f[10],c[10];
string ans,now;
void dfs(int dep,int limit)
{
    if (dep==limit)
    {
        if (ans=="" || now<ans)
            ans=now;
        return;
    }
    int x=c[dep],y=c[dep+1];
    for (int i=x;i!=0;i=f[i])
        if (a[i][y])
        {
            int pos=now.size();
            now+=v[y];
            f[y]=i;
            dfs(dep+1,limit);
            now.erase(pos);
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",v[i]);
            c[i]=i;
        }
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=a[y][x]=true;
        }
        ans="";
        while (1)
        {
            f[c[1]]=0;
            now+=v[c[1]];
            dfs(1,n);
            now.erase();
            if (!next_permutation(c+1,c+n+1))
                break;
        }
        static int id=0;
        printf("Case #%d: %s\n",++id,ans.c_str());
    }
    return(0);
}

