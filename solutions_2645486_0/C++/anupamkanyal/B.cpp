
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
	for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back
#define MP make_pair

typedef long long LL;

int e,r;
vector<int> V;
int N;
int dfs(int cur,int rem,int n) {
	if (n==N) return 0;
	int curcost=V[n]*cur;
	rem=min(rem+r,e);
	int res=0;
	REP(i,0,rem) res=max(res,dfs(i,rem-i,n+1));
	return res+curcost;
}

int main() {
	int t;
	cin >> t;
	REP(tc,1,t) {
		int n;
		cin >> e >> r >> n;
		N=n;
		V.clear();
		FOR(i,0,n) {
			int tmp;
			cin >> tmp;
			V.PB(tmp);
		}
		int ans=0;
		REP(i,0,e) ans=max(ans,dfs(i,e-i,0));
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
