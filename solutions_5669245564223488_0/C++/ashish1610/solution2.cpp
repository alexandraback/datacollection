/*	Problem B	*/
/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int ar[27][27],cnt[27],done[27];
long long int fact[108];
long long int dfs(int node)
{
    done[node]=1;
    long long int ret=fact[cnt[node]];
    for(int j=0;j<27;j++)
    {
        if(ar[node][j]&&!done[node])
            ret=(ret*1LL*dfs(j))%mod;
    }
    return ret;
}
int main()
{
    int m,t,i,j,k,l,n;
    int tt;
    cin>>t;
    fact[0]=1LL;
    tt=1;
    for(i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%mod;
    }
    while(t--)
    {

        memset(ar,0,sizeof(ar));
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        int fg=1;
        string s[n+9];
        int cnt1[27];
        memset(cnt1,0,sizeof(cnt1));
        memset(done,0,sizeof(done));
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
                ar[st][val]++;
                cnt1[val]++;
                if(ar[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                cnt[st]++;
        }
        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(ar[i][j])
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
                if(ar[i][j])
                    c++;
            }
            int g=0;
            if(c!=0&&cnt1[i]!=0)
                g=1;

            if(cnt[i]&&g)
            fg=0;
        }
        cout<<"Case #"<<tt++<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            long long int ans=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(done[i]||cnt1[i])
                   continue;
                int zz=0;
                if(cnt[i])
                    zz=1;

                for(j=0;j<26;j++)
                {
                    if(ar[i][j]||ar[j][i])
                    zz=1;
                }
                if(!zz)
                    continue;
                long long int z=dfs(i);
                ans=(ans*1LL*z)%mod;
                c++;
            }
            ans=(ans*1LL*fact[c])%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}

