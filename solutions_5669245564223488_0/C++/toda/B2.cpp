#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>

#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long LL;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
using namespace std;
#define mod 1000000007

long long powe(int a,int b)
{
    long long ans=1;
    long long c=a*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*c)%mod;
        c=(c*1LL*c)%mod;
        b=b/2;
    }
    return ans;
}
long long  modinv(int a)
{
    return powe(a,mod-2);
}
#define eps 1e-12
#define gc getchar_unlocked

int adj[27][27],coun[27],visit[27];
long long  fact[108];

long long  dfs(int node)
{
    visit[node]=1;

    long long  ret=fact[coun[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j]&&!visit[node])
            ret=(ret*1LL*dfs(j))%mod;
    }
    return ret;
}


int main()
{
    int m,t,i,j,k,l,n;
    int cs;
    freopen("inp3.in","r",stdin);
    freopen("out3.txt","w",stdout);
    cin>>t;
    fact[0]=1LL;
    cs=1;
    for(i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%mod;
    }
    while(t--)
    {

        memset(adj,0,sizeof(adj));
        memset(coun,0,sizeof(coun));
        cin>>n;
        int fg=1;
        string s[n+9];
        int indegree[27];
        memset(indegree,0,sizeof(indegree));
        memset(visit,0,sizeof(visit));
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            for(j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                adj[st][val]++;
                indegree[val]++;
                if(adj[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                coun[st]++;
        }

        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(adj[i][j])
                    c++;
            }
            if(c>1)
                fg=0;
        }

        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(adj[i][j])
                    c++;
            }
            int g=0;
            if(c!=0&&indegree[i]!=0)
                g=1;

            if(coun[i]&&g)
            fg=0;
        }
        cout<<"Case #"<<cs++<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            long long  ans=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(visit[i]||indegree[i])
                   continue;
                int flag=0;
                if(coun[i])
                    flag=1;

                for(j=0;j<26;j++)
                {
                    if(adj[i][j]||adj[j][i])
                    flag=1;
                }
                if(!flag)
                    continue;
                long long z=dfs(i);
                ans=(ans*1LL*z)%mod;
                c++;
            }
            ans=(ans*1LL*fact[c])%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
