#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1100;
int n;
bool b[maxn];
queue<int> q;
vector<int> a[maxn];
bool bfs(int S)
{
    while (!q.empty()) q.pop();
    memset(b,0,sizeof(b));
    q.push(S); b[S]=true;
    while (!q.empty())
    {
        int u=q.front();
        for (int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            if (b[v]==true) return true;
            b[v]=true;
            q.push(v);
        }
        q.pop();
    }
    return false;
}
void init()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int m,x;
        a[i].clear();
        scanf("%d",&m);
        for (int j=1; j<=m;j++)
        {
            scanf("%d",&x);
            a[i].push_back(x);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        init();
        bool q=false;
        for (int i=1; i<=n; i++)
        if (bfs(i))
        {
            q=true; break;
        }
        if (q) printf("Case #%d: Yes\n",tt); else
        printf("Case #%d: No\n",tt);
    }
}
