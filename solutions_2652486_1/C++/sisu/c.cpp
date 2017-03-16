#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long ll;
int R,N,M,K;
ll vs[16];
int cur[16];
unordered_map<ll,double> dp[16];
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
const int order[] = {3,6,5,7,2,4,8};
int fcnt(ll v, ll x) {
	int c=0;
	while(v%x==0) v/=x, c++;
	return c;
}
void solve(int n, int m) {
	if (m>=7) return;
	if (m==2 || m==3 || m==4) {
		int f = m==2 ? 3 : m==3 ? 5 : 7;
		int cc=0;
		for(int i=0; i<n; ++i) cc += cur[i]%f==0;
		for(int i=0; i<K; ++i) if (fcnt(vs[i], f)>cc) return;
	}
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
	cur[n] = order[m];
	dp[n].clear();
	solve(n+1, m);
	solve(n, m+1);
}
ll bin[16][16];
long double xprob(ll n, ll v) {
	long double res = 0;
	for(int i=0; i<K; ++i) {
		res += log2(bin[n][fcnt(vs[i], v)]) - n;
	}
	return res;
}
void solve2() {
	memset(res,0,sizeof(res));
	solve(0,0);
	return;
	int n = 0;
	for(int v : {5,7}) {
		int cnt = 0;
		for(int i=0; i<K; ++i) cnt = max(cnt, fcnt(vs[i], v));
		while(xprob(cnt+1, v) > xprob(cnt, v)) ++cnt;

//		cerr<<"cnt "<<v<<" : "<<cnt<<'\n';
		while(cnt--) dp[n].clear(), cur[n++] = v;
	}
	solve(n, 0);
}
int main() {
	for(int i=0; i<16; ++i) {
		bin[i][0] = 1;
		for(int j=1; j<=i; ++j) bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
	}
	int T;cin>>T;
	cin>>R>>N>>M>>K;
	cout<<"Case #1:\n";
	for(int a=0; a<R; ++a) {
		if (a%100==0) cerr<<a<<'\n';
		for(int k=0; k<K; ++k) cin>>vs[k];

		best = 0;
//		solve(0, 2);
		solve2();
		for(int i=0; i<N; ++i) cout<<res[i];
		cout<<'\n';
	}
}
