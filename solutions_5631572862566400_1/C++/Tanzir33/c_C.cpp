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
#define DBG         //pf("Hi\n")
#define pf          printf
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define PI          acos(-1.00)
#define sz          size()
#define xx          first
#define yy          second
#define eps         1e-9

typedef long long int LL;
typedef double db;
int cnt , vis[1010], E[1010], src, yes[1010];
vector<int> v;
int ans[1010];
int dfs(int nd)
{
    if(vis[nd] && src == nd)
        return cnt;
    else if(vis[nd])
        return 0;
    cnt++;
    vis[nd] = 1;
    return dfs(E[nd]);
}
void dfs2(int nd)
{
    vis[nd] = 1;
    if(!vis[E[nd]])
        dfs2(E[nd]);
    v.pb(nd);
}
void dfs3(int nd)
{
    //D(nd);getchar();
    if(yes[nd])
    {
        ans[nd] = max(ans[nd], cnt);
        return;
    }
    cnt++;
    vis[nd] = 1;
    if(!vis[E[nd]])
        dfs3(E[nd]);
}
int main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int i, j, k, cs, t, n;
    sf(t);
    FRE(cs,1,t)
    {
        mem(vis,0);
        mem(yes,0);
        v.clear();
        mem(ans,0);
        sf(n);
        FRE(i,1,n)
            sf(E[i]);
        FRE(i,1,n)
        {
            if(E[E[i]] == i)
                yes[i] = yes[E[i]] = 1;
        }
        int total = 0;
        FRE(i,1,n)
        {
            mem(vis,0);
            src = i;
            cnt = 0;
            total = max(total, dfs(src));
          //  D(total);
        }
        DBG;
        mem(vis,0);
        FRE(i,1,n)
        {
            if(!vis[i])
                dfs2(i);
        }
        DBG;
        mem(vis,0);
        for(i = n-1; i>=0; i--)
        {
            int nd = v[i];
            if(!yes[nd])
            {
                mem(vis,0);
                cnt = 0;
                dfs3(nd);
            }
        }
        //DBG;
        int tmp = 0;
        //D(total);
        for(i = 1; i<=n; i++)
        {
            if(yes[i])
                tmp++, tmp+= ans[i];
        }
        total = max(total, tmp);
        pf("Case #%d: %d\n",cs,total);
    }
    return 0;
}


