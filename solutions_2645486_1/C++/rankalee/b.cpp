#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m, e, r, v[10000], nj[20010];
ll dp[2][20010];

void run(){
	cin >> e >> r >> n;
	rep(i, n) cin >> v[i];
	
	vi vs;
	rep(i, n + 1){
		if(e - i * r > 0) vs.pb(e - i * r);
		else break;
	}
	rep(i, n + 1){
		if(i * r <= e) vs.pb(i * r);
		else break;
	}
	sort(all(vs)); vs.erase(unique(all(vs)), vs.end());
	
	m = vs.size();
	rep(i, m){
		if(!binary_search(all(vs), min(e, vs[i] + r))) nj[i] = 0;
		else nj[i] = lower_bound(all(vs), min(e, vs[i] + r)) - vs.begin();
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][m - 1] = 0;
	
	int cur = 0, next = 1;
	ll ans = 0;
	rep(i, n){
		memset(dp[next], -1, sizeof(dp[next]));
		
		ll mx = -inf;
		for(int j = m - 1; j >= 0; j--){
			
			if(dp[cur][j] >= 0) mx = max(mx, dp[cur][j] + (ll)vs[j] * v[i]);
			if(j == m - 1) continue;
			
			ll nxt = mx - (ll)vs[j] * v[i];
			dp[next][nj[j]] = max(dp[next][nj[j]], nxt);
		}
		swap(cur, next);
	}
	rep(i, m) ans = max(ans, dp[cur][i]);
	cout << ans << endl;
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": ";
		run();
	}
	return 0;
}
