#include<bits/stdc++.h>
using namespace std;
int adj[27][27],reps[27],vis[27];
long long int fact[108];
#define MOD 1000000007
long long int dfs(int node)
{
    vis[node]=1;
    long long int ret=fact[reps[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j]&&!vis[node])
            ret=(1LL*ret*dfs(j))%MOD;
    }
    return ret;
}


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    fact[0]=1;
    for(int i=1;i<=100;i++)
    {
        fact[i]=(1LL*fact[i-1]*i)%MOD;
    }
    for(int tt=1;tt<=t;tt++)
    {
        int come[27];
        memset(come,0,sizeof(come));
        memset(vis,0,sizeof(vis));
        memset(adj,0,sizeof(adj));
        memset(reps,0,sizeof(reps));
        int n;
        cin >> n;
        int fg=1;
        string s[n+9];
        int m,k,l;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int flg=0;
            for(int j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                flg=1;
                adj[st][val]++;
                come[val]++;
                if(adj[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!flg)
                reps[st]++;
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

        for(int i=0;i<26;i++)
        {
            int c=0;
            for(int j=0;j<26;j++)
            {
                if(adj[i][j])
                    c++;
            }
            int g=0;
            if(c!=0&&come[i]!=0)
                g=1;

            if(reps[i]&&g)
            fg=0;
        }
        cout<<"Case #"<<tt<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            long long int ans=1;
            int c=0;
            for(int i=0;i<26;i++)
            {
                if(vis[i]||come[i])
                   continue;
                int flz=0;
                if(reps[i])
                    flz=1;

                for(int j=0;j<26;j++)
                {
                    if(adj[i][j]||adj[j][i])
                    flz=1;
                }
                if(!flz)
                    continue;
                long long int z=dfs(i);
                ans=(ans*1LL*z)%MOD;
                c++;
            }
            ans=(1LL*ans*fact[c])%MOD;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
