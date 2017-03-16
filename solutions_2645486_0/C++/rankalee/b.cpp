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

int n, e, r, v[10000];
int dp[11][6];

void run(){
	cin >> e >> r >> n;
	rep(i, n) cin >> v[i];
	memset(dp, -1, sizeof(dp));
	
	dp[0][e] = 0;
	rep(i, n) rep(j, e + 1) if(dp[i][j] >= 0){
		rep(k, j + 1){
			int next = dp[i][j] + v[i] * (j - k);
			dp[i + 1][min(k + r, e)] = max(dp[i + 1][min(k + r, e)], next);
		}
	}
	int ans = 0;
	rep(i, e + 1) ans = max(ans, dp[n][i]);
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
