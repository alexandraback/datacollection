#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<bitset>
#include<map>

#define eps 1e-12
#define gc getchar_unlocked
#include<stack>
using namespace std;
#define MOD 1000000007
#define inf 10000000


long long powerr(int aa,int b)
{
    long long ans=1;
    long long a=aa*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*a)%MOD;
        a=(a*1LL*a)%MOD;
        b=b/2;
    }
    return ans;
}
long long MODinv(int a)
{
    return powerr(a,MOD-2);
}
#define eps 1e-12
#define gc getchar_unlocked
int adj[27][27],coun[27],vis[27],ctr[27];
long long fact[108];
int fg;
long long dfs(int node)
{
    vis[node]=1;

    long long ret=fact[coun[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j])
        {
            if(vis[j]&&!ctr[j])
                return 0;
            else
                ret=(ret*1LL*dfs(j))%MOD;
        }
    }
    return ret;
}


int main()
{
    freopen("b.in","r",stdin);
    freopen("bout.txt","w",stdout);
    int m,test,i,j,k,l,n;
    int cases;
    scanf("%d",&test);

    fact[0]=1LL;
    cases=1;
    for(i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%MOD;
    }
    while(test--)
    {

        memset(adj,0,sizeof(adj));
        memset(coun,0,sizeof(coun));
        scanf("%d",&n);

        fg=1;
        string s[n+9];
        int indeg[27];

        memset(indeg,0,sizeof(indeg));
        memset(vis,0,sizeof(vis));
        map<int,int>ma;
        ma.clear();
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            ma[st]=1;
            for(j=1;j<s[i].length();j++)
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
            if(c!=0&&indeg[i]>1)
                g=1;

            if(coun[i]&&g)
            fg=0;
        }

        cout<<"Case #"<<cases++<<": ";

        memset(ctr,0,sizeof(ctr));
        if(!fg)
            cout<<"0\n";
        else
        {
            long long ans=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(vis[i]||indeg[i])
                   continue;

                if(!ma[i])
                    continue;
                long long zo=dfs(i);
                ans=(ans*1LL*zo)%MOD;
                c++;
            }

            ans=(ans*1LL*fact[c])%MOD;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
