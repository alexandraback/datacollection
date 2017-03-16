
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

typedef long long ll;

map <pair<int,pair<int,int> >, int > M;
int J, P, S, K;

int done(int x, int y, int z) {
	if(M[mp(x,mp(y,z))] >= K) return 1;
	return 0;
}

void add(int x, int y, int  z) {
	M[mp(x,mp(y,z))]++;
}

int main() {
	int tt;
	cin >> tt;
	REP(test,tt) {
		cin >> J >> P >> S >> K;
		M.clear();
		cout << "Case #" << test+1 << ": ";
		vector<pair<int,pair<int,int> > > ans;
		for(int i = 0; i < J; i++) {
			for(int j = 0; j < P; j++) {
				for(int k = 0; k < S; k++) {
					if(done(i,j,-1) || done(-1,j,k) || done(i,-1,k)) continue;
					ans.pb(mp(i+1,mp(j+1,k+1)));
					add(i,j,-1); add(i,-1,k); add(-1,j,k);
				}
			}
		}
		cout << sz(ans) << endl;
		REP(i,sz(ans)) cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	}
}

