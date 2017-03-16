#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#define eps 1e-9
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi acos(-1.0)
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define inf 2000000000
#define MOD 1000000007

using namespace std;

bool vis[1010],chk;
vector<int>mat[1010];


void dfs(int u)
    {
    vis[u]=1;
    int ul=mat[u].size();
    for(int i=0;i<ul;i++)
        {
        int v=mat[u][i];
        if(!vis[v]) dfs(v);
        else {chk=true;return;}
        }
    return;
    }

int main()
{
/*
freopen("A-small-attempt0.in","r",stdin);
freopen("Aout.txt","w",stdout);
*/
int t,kk=1,x,y,n;
cin>>t;
while(t--)
    {
    cin>>n;
    for(int i=0;i<1010;i++)
        mat[i].clear();
    for(int i=1;i<=n;i++)
        {
        cin>>x;
        for(int j=1;j<=x;j++)
            {
            cin>>y;
            mat[i].pb(y);
            }
        }
    chk=false;

    for(int i=1;i<=n;i++)
        {
        if(chk) break;
        CLR(vis);
        dfs(i);
        }

    cout<<"Case #"<<kk++<<": ";
    if(chk) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
return 0;
}
