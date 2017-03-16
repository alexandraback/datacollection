#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const string f="gcj22";
const string fin=f+".in";
const string fout=f+".out";

ll ways[55];
int g[55][55];
ll m;
int n;

void solve()
{
    memset(g,0,sizeof g);
    memset(ways,0,sizeof ways);
    for(int i=2;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            g[i][j]=1;
    ways[n]=1;
    for(int i=n-1;i>=2;i--)
        for(int j=i+1;j<=n;j++)
            ways[i]+=ways[j];
    for(int i=2;i<=n;i++)
        if(ways[1]+ways[i]<=m)
            ways[1]+=ways[i],g[1][i]=1;
}

int main()
{
    freopen(fin.c_str(),"r",stdin);
    freopen(fout.c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    int T=0;
    while(t--)
    {
        T++;
        cin>>n>>m;
        cout<<"Case #"<<T<<":";
        solve();
        if(ways[1]!=m)
        {
            cout<<" IMPOSSIBLE\n";
            continue;
        }

        cout<<" POSSIBLE\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<g[i][j];
            cout<<"\n";
        }
    }
    return 0;
}
