#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define D(x) cout << #x << " = " << (x) << endl;
#define all(x) (x).begin(),(x).end()
const int MAX = 1001;
int n;
int Next[MAX];
int vis[MAX];
vector<vector<int> > g;

int dfs(int u,int src){
	int v = Next[u];
	if(v==src)
		return 1;
	if(vis[v]) return -100000000;
	vis[v] = 1;
	return 1 + dfs(v,src);
}

int fun(int u,int p){
	int r = 1;
	for(int i=0;i<(int)g[u].size();i++){
		int v = g[u][i];
		if(v!=p){
			r = max(r,1+fun(v,u));
		}
	}
	return r;
}

int main()
{
    freopen("/home/khaled/file.in","r",stdin);
    freopen("/home/khaled/file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
		cin >> n;
		g.clear();
		g.resize(n);
		for(int i=0;i<n;i++){
			cin >> Next[i];
			--Next[i];
			g[ Next[i] ].push_back(i);
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			memset(vis,0,sizeof vis);
			int calc = dfs(i,i);
			ans = max(ans,calc);
		}
		int sum = 0;
		for(int i=0;i<n;i++){
			int j = Next[i];
			if(i==Next[j]){
//				cout << "here" << endl;
//				cout << i+1 << " " << fun(i,j) << endl;
				int c = fun(i,j) + fun(j,i);
				sum += c;
			}
		}
		ans = max(ans,sum/2);
		cout << "Case #" << tc++ << ": " << ans << endl;
    }
    return 0;
}



