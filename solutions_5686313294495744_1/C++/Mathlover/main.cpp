#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
const int N=1005;
int uN,vN;
int g[N][N];
int linker[N];
bool used[N];
bool dfs(int u)
{
    for(int v=0;v<vN;++v)
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=1;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return false;
}
int solve()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<uN;++u)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;

}
int main()
{
    freopen("C-large (2).in","r",stdin);
    freopen("2.out","w",stdout);
    int ca=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map<string,int>hsu,hsv;
        memset(g,0,sizeof(g));
        int n;
        uN=vN=0;
        scanf("%d",&n);
        string temp;
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            int u,v;
            cin>>temp;
            if(hsu.find(temp)==hsu.end())
                hsu[temp]=u=uN++;
            else u=hsu[temp];
            cin>>temp;
            if(hsv.find(temp)==hsv.end())
                hsv[temp]=v=vN++;
            else v=hsv[temp];
            g[u][v]=1;
        }
//        for(int i=0;i<uN;++i)
//            for(int j=0;j<vN;++j)
//                printf("%d%c",g[i][j]," \n"[j==vN-1]);
//        printf("%d %d\n",uN,vN);
        printf("Case #%d: %d\n",++ca,n-(uN+vN-solve()));
    }
}
