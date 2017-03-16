#include <bits/stdc++.h>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define dbg(e)  cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define REP(i,n) FOR(i,0,n)
#define pb  push_back
#define mp make_pair
#define INF (1 << 29)

int a[105][55];
map<int,int> M;

int main() {
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		M.clear();
		REP(i,2*n-1) REP(j,n) cin >> a[i][j];
		REP(i,2*n-1) REP(j,n) {
			M[a[i][j]]++;
		}
		vector<int> ans;
		EACH(it,M) if(it->second % 2) ans.pb(it->first);
		cout << "Case #" << tt+1 << ": ";
		REP(i,sz(ans)) cout << ans[i] << " ";
		cout << endl;
	}
}
