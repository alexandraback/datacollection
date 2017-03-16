#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define MN 1005
#define N 1005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int from,to,pre;
}e[MN];
int h[MN]={0},cou=0;
void Addedge(int from,int to)
{
    cou++;
    e[cou]=((Edge){from,to,h[from]});
    h[from]=cou;
}

bool stk[MN];
int dfn[MN]={0},low[MN],cnt,sum[N],num,ans;
stack<int> s;
void tarjan(int x)
{
    int i,v;
    dfn[x]=low[x]=++num;
    s.push(x); stk[x]=1;
    for(i=h[x];i;i=e[i].pre)
    {
        v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(stk[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        do
        {
            v=s.top();
            s.pop(); stk[v]=0;
            sum[cnt]++;
        }while(v!=x);
        ans=max(ans,sum[cnt]);
    }
}

int bf[N],dep[N],dp[N];
vector<int> G[N];
vector<int> st;
bool mp[N][N];
void dfs(int x)
{
    int i;
    dp[x]=dep[x];
    for(i=0;i<G[x].size();i++)
        if(!dep[G[x][i]])
        {
            dep[G[x][i]]=dep[x]+1;
            dfs(G[x][i]);
            dp[x]=max(dp[x],dp[G[x][i]]);
        }
}

int main()
{
    int T,test;
    int n,i;
    freopen("Csmall1.in","r",stdin);
    freopen("Csmall1.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        cin>>n;
        num=0,cnt=0,
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(stk,0,sizeof(stk));
        memset(dep,0,sizeof(dep));
        memset(dp,0,sizeof(dp));
        cou=0;
        ans=0;
        memset(h,0,sizeof(h));
        memset(mp,0,sizeof(mp));
        memset(sum,0,sizeof(sum));
        st.clear();
        while(!s.empty()) s.pop();
        for(i=1;i<=n;i++)
            G[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&bf[i]);
            Addedge(i,bf[i]);
            G[bf[i]].push_back(i);
            mp[i][bf[i]]=1;
            if(mp[bf[i]][i])
            {
                dep[i]=dep[bf[i]]=1;
                st.push_back(i);
                st.push_back(bf[i]);
            }
        }
        for(i=1;i<=n;i++)
            if(!dfn[i])
                tarjan(i);
        //debug(ans);
        int ans2=0;
        for(i=0;i<st.size();i+=2)
        {
            dfs(st[i]);
            dfs(st[i+1]);
            //debug(st[i]);
            //debug(st[i+1]);
            ans2+=(dp[st[i]]+dp[st[i+1]]);
        }
        ans=max(ans,ans2);
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))
