#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a)    for(int i = 0;i < a;i++)
#define REP(i,a,b)  for(int i = a;i < b;i++)
#define vi vector<int>

bool vis[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    cin>>t;
    REP(a,1,t+1)
    {
        long long n;
        cin>>n;
        fill(vis,vis+n+1,false);
        queue<pair<long long,long long> >q;
        q.push({1,1});
        long long ans=n;
        while(!q.empty())
        {
            pair<long long,long long>pi=q.front();
            q.pop();
            if(pi.first==n)
            {
                ans=min(pi.second,ans);
                break;
            }
            if(pi.first+1<=n&&vis[pi.first+1]==false)
            {
                q.push({pi.first+1,pi.second+1});
                vis[pi.first+1]=true;
            }
            long long tmp2=pi.first;
            long long tmp1=0;
            while(tmp2!=0)
            {
                tmp1+=(tmp2%10);
                tmp2/=10;
                if(tmp2!=0)
                {
                    tmp1*=10;
                }
            }
            if(tmp1<=n&&vis[tmp1]==false)
            {
                q.push({tmp1,pi.second+1});
                vis[tmp1]=true;
            }
        }
        cout<<"Case #"<<a<<": "<<ans<<endl;
    }
    return 0;
}
