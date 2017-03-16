#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define endl '\n'
#define gcd __gcd
#define lcm(x,y) ((x)*(y)/gcd(x,y))
#define smin(x,y) (x=min(x,y))
#define smax(x,y) (x=max(x,y))
#define sgcd(x,y) (x=gcd(x,y))
#define slcm(x,y) (x=lcm(x,y))
#define obt __builtin_popcount
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define rsort(x,y) sort(x,y),reverse(x,y);
#define dbg(x) cerr<<#x<<": "<<x<<endl
using namespace std;
vector<int> al[1010];
int b[1010],d[1010],p[1010];
int dfs(int v)
{
    int ok=0;
    for(int i=0;i<al[v].size();i++)
        if(p[v]-al[v][i])
            ok=max(ok,dfs(al[v][i]));
    return ok+1;
}
int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
    int t;
    cin>>t;
    for(int _=0;_<t;_++)
    {
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
            al[i].clear(),b[i]=0,d[i]=0;
        for(int i=0;i<n;i++)
            cin>>p[i],p[i]--,al[p[i]].pb(i);
        for(int i=0;i<n;i++)
        {
            int k=i,l=-1,w=1;
            while(!b[k])
                b[k]=w,l=k,k=p[k],w++;
            if(b[k]==-1)
            {
                k=i;
                while(b[k]+1)
                    b[k]=-1,k=p[k];
            }
            else if(p[k]-l)
            {
                ans=max(ans,w-b[k]);
                k=i;
                while(b[k]+1)
                    b[k]=-1,k=p[k];
            }
            else
            {
                k=i;
                while(b[k])
                    b[k]=0,k=p[k];
            }
        }
        for(int i=0;i<n;i++)
            if(b[i]+1 && p[p[i]]==i)
                d[i]=dfs(i);
        int h=0;
        for(int i=0;i<n;i++)
            if(b[i]+1 && p[p[i]]==i)
                h+=d[i];
        ans=max(ans,h);
        cout<<"Case #"<<_+1<<": "<<ans<<endl;
    }
    return 0;
}
