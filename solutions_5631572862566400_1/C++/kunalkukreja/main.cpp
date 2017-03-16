#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

vector<vi> adj;
vi vis;

int ma;

void dfs(int i,int p,int l)
{
    vis[i] = 1;
    ma = max(ma,l);
    fore(j,0,adj[i].sz)
    {
        if(adj[i][j] == p)
            continue;
        dfs(adj[i][j],-1,l+1);
    }
}
void dfs2(int i,int l,int cur)
{
    vis[i] = cur;
    fore(j,0,adj[i].sz)
    {
        if(vis[adj[i][j]] == cur) {
            ma = max(ma,l);
            continue;
        }
        else if(vis[adj[i][j]])
            continue;
        dfs2(adj[i][j],l+1,cur);
    }
}
int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int n;
		cin>>n;
		vector<pii> dost;
		adj.clear();
		vis.clear();
		adj.resize(n);
		vector<vi> mat(n,vi(n,0));
		fore(i,0,n)
        {
            int x;
            cin>>x;
            x--;
            adj[x].pb(i);
            mat[min(i,x)][max(i,x)]++;
            if(mat[min(i,x)][max(i,x)] == 2)
                dost.pb(mp(i,x));
        }
        vis.resize(n);
        fore(i,0,n)
            vis[i] = 0;
        int fa = 0;
        fore(i,0,dost.sz)
        {
            ma = 1;
            dfs(dost[i].ff,dost[i].ss,1);
            int ans = ma;
            ma = 1;
            dfs(dost[i].ss,dost[i].ff,1);
            ans+=ma;
            fa+=ans;
        }
        int cur = 2;
        fore(i,0,n)
        {
            if(vis[i])
                continue;
            ma = 0;
            dfs2(i,1,cur);
            fa = max(fa,ma);
            cur++;
        }
        cout<<fa<<endl;
	}
	return 0;
}
