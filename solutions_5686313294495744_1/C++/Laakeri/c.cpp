#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

struct MaxFlow {
	// Use vector<map<int, ll> > for sparse graphs
	vector<vector<ll> > f;
	vector<vector<int> > g;
	vector<int> used;
	int cc;
	
	ll flow(int x, int t, ll fl, ll miv) {
		if (x==t) return fl;
		used[x]=cc;
		for (int nx:g[x]) {
			if (used[nx]!=cc&&f[x][nx]>=miv) {
				ll r=flow(nx, t, min(fl, f[x][nx]), miv);
				if (r>0) {
					f[x][nx]-=r;
					f[nx][x]+=r;
					return r;
				}
			}
		}
		return 0;
	}
	
	// maxv is maximum expected maxflow
	ll getMaxFlow(int source, int sink, ll maxv) {
		cc=1;
		ll r=0;
		ll k=1;
		while (k*2<=maxv) k*=2;
		for (;k>0;k/=2) {
			while (ll t=flow(source, sink, maxv, k)) {
				r+=t;
				cc++;
			}
			cc++;
		}
		return r;
	}
	
	void addEdge(int a, int b, ll c) {
		if (f[a][b]==0&&f[b][a]==0) {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		f[a][b]+=c;
	}
	
	MaxFlow(int n) : f(n+1), g(n+1), used(n+1) {
		for (int i=1;i<=n;i++) {
			f[i]=vector<ll>(n+1);
		}
	}
};

void solve(){
	int id1=1;
	int id2=1;
	int n;
	cin>>n;
	MaxFlow mf(n*3+20);
	map<string, int> lol1;
	map<string, int> lol2;
	for (int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if (lol1[s1]==0) lol1[s1]=id1++;
		if (lol2[s2]==0) lol2[s2]=id2++;
		mf.addEdge(lol1[s1], lol2[s2]+n+5, 1);
	}
	for (int i=1;i<=n;i++){
		mf.addEdge(n*3+7, i, 1);
		mf.addEdge(i+n+5, n*3+8, 1);
	}
	int f=mf.getMaxFlow(n*3+7, n*3+8, 1);
	int v=f+((int)lol1.size()+(int)lol2.size()-2*f);
	cout<<n-v<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tcs;
	cin>>tcs;
	for (int tc=1;tc<=tcs;tc++){
		cout<<"Case #"<<tc<<": ";
		solve();
	}
}