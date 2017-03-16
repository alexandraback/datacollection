//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define PI  acos(-1.0)
#define eps 1e-8
#define LL  long long
#define PB  push_back
#define MP  make_pair
#define PQ  priority_queue
#define MII map<int,int>::iterator
#define MLL map<LL,LL>::iterator
#define PII pair<int,int>
#define SI  set<int>::iterator
#define SL  set<LL>::iterator
#define MSI map<string,int>::iterator
#define IN  freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
#define BUG printf("bug************bug************bug\n");

#define MEM(a,b) memset(a,b,sizeof(a))
#define M_SI     multiset<int>::iterator

using namespace std;
const int maxn=5000000+10;
int ans[maxn];
bool vis[maxn];

struct node
{
    int x,s;
    node(int x,int s):x(x),s(s){}
};

void BFs()
{
    MEM(vis,0);
    vis[1]=1;
    queue<node>q;
    q.push(node(1,1));
    while(!q.empty())
    {
        node tp=q.front(); q.pop();
        int u=tp.x;
        ans[u]=tp.s;
        int v=0;
        while(u)
        {
            v=v*10+u%10;
            u/=10;
        }
        if (v<maxn && !vis[v]) {vis[v]=1; q.push(node(v,tp.s+1)); }
        if (tp.x+1>=maxn) continue;
        if (!vis[tp.x+1])
        {
            vis[tp.x+1]=1;
            q.push(node(tp.x+1,tp.s+1));
        }
    }
}
int main()
{
    IN; OUT;
    BFs();
    int t,cas=0,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",++cas,ans[n]);
    }
    return 0;
}
