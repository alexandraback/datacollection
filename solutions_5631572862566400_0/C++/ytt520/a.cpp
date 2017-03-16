#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <map>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;
#define LL long long
#define B 240
#define eps 1e-8
#define MP make_pair
#define Pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define ls (o << 1)
#define rs (2*o + 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define MOD 998244353
const int N = 3030;
int a[N],b[N];
int n,num,stack[N],head[N],top,vis[N];
bool incircle[N],instack[N];
vector<int>stor,circle[N],H[N];
struct Edge{
    int to,next;
}e[2*N];

void add(int u,int v)
{
    e[num].next = head[u];
    e[num].to = v;
    head[u] = num++;
}
int tim;
void dfs(int u)
{
    vis[u] = tim;
    instack[u] = true;
    stack[top++] = u;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v = e[i].to;
        if(vis[v]==tim){
         int p ;
         do{
            p = stack[top-1];
            stor.push_back(p);
            incircle[p] = true;
            instack[p] = false;
            top--;
         }while(p!=v);
            continue;
        }else if (vis[v] == 0)dfs(v);
    }
    if(instack[u]){
        instack[u] = false;
        top--;
    }
}
int gao(int u,int fa)
{
    int ret = 0;
    for(int i=0;i<H[u].size();i++){
        int v = H[u][i];
        if(v == fa||incircle[v])continue;
        ret = max(ret,gao(v,u)+1);
    }
    return ret;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        num = 0;
        for(int i=1;i<=n;i++)H[i].clear();
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            add(i,a[i]);
            circle[i].clear();
            H[i].push_back(a[i]);
            H[a[i]].push_back(i);
        }
        int tot = 0;
        memset(vis,0,sizeof(vis));
        memset(incircle,0,sizeof(incircle));
        memset(instack,0,sizeof(instack));
        tim = 0;
        for(int i=1;i<=n;i++)
        if(!vis[i]){
            tim++;
            dfs(i);
           if(stor.size()>0){
               // printf("Yes\n");
                tot++;
                for(int i = 0;i<stor.size();i++){
               //    printf(" %d",stor[i]);
                   circle[tot].push_back(stor[i]);
                }
               // printf("\n");
            }
            stor.clear();
        }
        int ans = 0;
        for(int i=1;i<=tot;i++){
            int p = circle[i].size();
            if(p>2){
                ans = max(p,ans);
            }else{
                int tmp = 0;
                for(int j=0;j<p;j++){
                    tmp+=gao(circle[i][j],0);
                }
                ans = max(ans,tmp+p);
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
