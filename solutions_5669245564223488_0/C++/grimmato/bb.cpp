#define TRACE
#define DEBUG
//#define debug
#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include <deque>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i,n) for(i = 0; i < n; i++) // for [0,n)
#define FORR(i,n) for(int i=(n);i>=0;i--) // reverse for [n,0)
#define FOREX(i,a,b) for(i = a; i < b ; i++) // for [a,b)
#define FORAB(i, a, b) for(i = a; i <= b; i++) // for [a,b]
#define ALL(V) V.begin(), V.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;

#ifdef TRACE
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define trace(x) cerr << x;
 
#else
 
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define trace(x)
 
#endif
#define mod 1000000007
template <class T> inline void chkmin(T &a, T b) { if (a>b) a=b; }
template <class T> inline void chkmax(T &a, T b) { if (a<b) a=b; }
template <class T>
void swap(T &a, T b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}


typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vii;
typedef vector<vii> vvii;

#define IN(A, B, C) assert( B <= A && A <= C)

typedef long long int LL;
typedef unsigned long long int ULL;

LL power(int aa,int b)
{
    LL ans=1;
    LL a=aa*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b=b/2;
    }
    return ans;
}
LL modinv(int a)
{
    return power(a,mod-2);
}

int adj[27][27],coun[27],vis[27];
LL fact[108];

LL dfs(int node)
{
    vis[node]=1;

    LL ret=fact[coun[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j]&&!vis[node])
            ret=(ret*1LL*dfs(j))%mod;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    #ifdef debug
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    freopen("log.txt", "w", stderr);
    #endif
    fact[0]=1LL;
    for(int i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%mod;
    }
    int T,n;
    cin>>T;
    for(int cases = 1 ; cases <= T ; cases++)
    {
    	memset(adj,0,sizeof(adj));
        memset(coun,0,sizeof(coun));
        cin>>n;
        int fg=1;
        string s[109];
        int indeg[27];
        memset(indeg,0,sizeof(indeg));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            for(int j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                adj[st][val]++;
                indeg[val]++;
                if(adj[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                coun[st]++;
        }

        for(int i=0;i<26;i++)
        {
            int c=0;
            for(int j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(adj[i][j])
                    c++;
            }
            if(c>1)
                fg=0;
        }
        //cout<<coun[0]<<"\n";
        cout<<"Case #"<<cases<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            LL ans=1LL;
            int c=0;
            for(int i=0;i<26;i++)
            {
                if(vis[i]||indeg[i])
                   continue;
                int zz=0;
                if(coun[i])
                    zz=1;
                for(int j=0;j<26;j++)
                {
                    if(adj[i][j])
                    zz=1;
                }
                if(!zz)
                    continue;
                LL z=dfs(i);
                ans=(ans*1LL*z)%mod;
                c++;
            }
            ans=(ans*1LL*fact[c])%mod;
            cout<<ans<<"\n";
        }

    }
}


















