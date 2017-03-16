#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define DBG         pf("Hi\n")
#define pf          printf
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define PI          acos(-1.00)
#define sz          size()
#define xx          first
#define yy          second
#define eps         1e-9
#define MAX         4000

typedef long long int LL;
typedef double db;

pair <string, string> S[MAX+10];
map <string, int> M1, M2;
int total1[MAX+10], total2[MAX+10];
int Left[MAX+10], Right[MAX+10];
bool Mark1[MAX+10], Mark2[MAX+10];
bool vis[MAX+10];
vector<int> E[MAX+10];
bool dfs(int u)
{
    if(vis[u])
        return false;
    vis[u] = true;
    for(int i = 0; i<E[u].sz; i++)
    {
        int v = E[u][i];
        if(Right[v] == -1)
        {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }
    for(int i = 0; i<E[u].sz; i++)
    {
        int v = E[u][i];
        if(dfs(Right[v]))
        {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }
    return false;
}

int BPM(int n)
{
    mem(Left,-1);
    mem(Right,-1);
    bool done = false;
    while(!done)
    {
        done = true;
        mem(vis,0);
        for(int i = 1; i<=n; i++)
        {
            if(Left[i] == -1 && dfs(i))
                done = false;
        }
    }
    int ret = 0;
    for(int i = 1; i<=n; i++)
        ret += (Left[i] != -1);
    return ret;
}
int yes1[MAX+10], yes2[MAX+10];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i, j, k, cs, t, n;
    sf(t);
    FRE(cs,1,t)
    {
        M1.clear(),M2.clear();
        mem(total1,0), mem(total2,0);
        mem(Mark1,0), mem(Mark2,0);
        mem(yes1,0), mem(yes2,0);
        sf(n);
        int cnt1 = 1, cnt2 = 1;
        FRE(i,1,n)
        {
            cin >> S[i].xx >> S[i].yy;
            if(!M1[S[i].xx])
                M1[S[i].xx] = cnt1++;
            if(!M2[S[i].yy])
                M2[S[i].yy] = cnt2++;
            total1[M1[S[i].xx]]++;
            total2[M2[S[i].yy]]++;
        }
        int ans = n;
        //D(ans);
        FRE(i,1,n)
        {
            int a = M1[S[i].xx], b = M2[S[i].yy];
            if(total1[a] == 1 || total2[b] == 1)
                ans--, Mark1[a] = 1, Mark2[b] = 1;
        }
        //D(ans);
        int X = 0;
        FRE(i,1,n)
        {
            int a = M1[S[i].xx], b = M2[S[i].yy];
            if((Mark1[a] + Mark2[b]) == 0)
                E[a].pb(b);
            if(!yes1[a] && !Mark1[a])
                yes1[a] = 1,X++;
            if(!yes2[b] && !Mark2[b])
                yes2[b] = 1, X++;
        }
        ans-=(X-BPM(max(cnt1,cnt2)));
        printf("Case #%d: %d\n",cs,ans);
        FRE(i,1,3000)
            E[i].clear();
    }
    return 0;
}


