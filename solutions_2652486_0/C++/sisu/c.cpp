#include <iostream>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
int R,N,M,K;
ll vs[16];
int cur[16];
map<ll,double> dp[16];
double dfs(int n, ll t) {
	if (n<0) return t==1;
	if (dp[n].count(t)) return dp[n][t];
	double r = 0;
	int v = cur[n];
	assert(v);
	if (t%v==0) r += .5 * dfs(n-1, t/v);
	r += .5 * max(r, dfs(n-1, t));
	return dp[n][t] = r;
}
double best;
int res[16];
void solve(int n, int m) {
	if (m>M) return;
	if (n==N) {
		double val = 1;
//		cout<<"testing: ";for(int i=0; i<N; ++i) cout<<cur[i]<<' ';cout<<'\n';
		for(int i=0; i<K; ++i) {
			val *= dfs(N-1, vs[i]);
//			cout<<"res "<<i<<' '<<vs[i]<<" : "<<dfs(N-1, vs[i])<<'\n';
		}
		if (val>best) {
			best = val;
			for(int i=0; i<K; ++i) res[i] = cur[i];
		}
		return;
	}
	cur[n] = m;
	dp[n].clear();
	solve(n+1, m);
	solve(n, m+1);
}
int main() {
	int T;cin>>T;
	cin>>R>>N>>M>>K;
	cout<<"Case #1:\n";
	for(int a=0; a<R; ++a) {
		for(int k=0; k<K; ++k) cin>>vs[k];

		best = 0;
		solve(0, 2);
		for(int i=0; i<N; ++i) cout<<res[i];
		cout<<'\n';
	}
}
