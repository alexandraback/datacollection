/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define CASE(n) printf("Case #%d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos){ return n=n | (1<<pos);}
int RESET(int n,int pos){ return n=n & ~(1<<pos);}
int CHECK(int n,int pos){ return (bool) (n & (1<<pos));}


int bigMod(int n,int power,int MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        int ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

int modInverse(int n,int MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}

int inverse(int x)
{
    dd p=((dd)1.0)/x;
    return (p)+EPS;
}

int gcd(int a, int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int nC2(int n)
{
    return n*(n-1)/2;
}

int MOD(int n,int mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

vector<int>g[1005],g_rev[1005];
int vis[1005],cnt,vv[1005][1005];

int dfs(int u)
{
    vis[u]=1;
    cnt++;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
//    read();
//    write();
	int t,cas=0;
	getint(t);
	while(t--)
    {
        int n;
        getint(n);
        mem(vv,0);
        for(int i=1;i<=n;i++)
        {
            int p;
            getint(p);
            g[i].pb(p);
            g_rev[p].pb(i);
            vv[i][p]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vv[i][j] && vv[j][i])
                {
                    for(int k=0;k<g_rev[i].size();k++)
                    {
                        int v=g_rev[i][k];
                        if(v==j)
                            continue;
                        g[i].pb(v);
                        break;
                    }
                    for(int k=0;k<g_rev[j].size();k++)
                    {
                        int v=g_rev[j][k];
                        if(v==i)
                            continue;
                        g[j].pb(v);
                        break;
                    }
                }
            }
        }
        mem(vis,0);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cnt=0;
                dfs(i);
                ans=max(ans,cnt);
            }
        }
        CASE(cas);
        pf("%d\n",ans);
        loop(i,1005)
        {
            g[i].clear();
            g_rev[i].clear();
        }
    }
	return  0;

}
