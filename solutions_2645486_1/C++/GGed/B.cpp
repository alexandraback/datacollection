#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

LLD m, r, n, ret;
LLD a[10005], dp[2][10005];
LLD dp2[3005][3005];


LLD solve2(){
	long long x;
	ret = 0;
	CLR(dp2, 0);
	FOR(i,0,n){
		scanf("%lld", &x);
		FOE(j,0,m){
			FOE(k,0,j){
				dp2[i+1][min(m, j - k + r)] = max(dp2[i+1][min(m, j - k + r)], dp2[i][j] + k * x);
			}
		}
	}
	FOE(j,0,m) ret = max(ret, dp2[n][j]);
	return ret;
}


void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%lld%lld%lld", &m, &r, &n);
	if (r > m) r = m;
	
	if (m <= 3000){
		printf("%lld\n", solve2());
	}
	else{
		int mx = min(n, m / r);
		long long R = m - mx * r;
		ret = 0;
		CLR(dp[1], -1);

		FOR(i,0,n){
			scanf("%lld", &a[i]);
			CLR(dp[i&1], -1);

			LLD best = -(1LL<<50);
			if (dp[i&1^1][mx] != -1) best = dp[i&1^1][mx] + r * a[i] * mx;
			for (int j=mx; j>=1; j--){
				if (dp[i&1^1][j-1] != -1) best = max(best, dp[i&1^1][j-1] + r * a[i] * (j - 1));
		        dp[i&1][j] = max(dp[i&1][j], best + r * a[i] * (1 - j));
			}

			FOE(j,1,mx){
				dp[i&1][j] = max(dp[i&1][j], a[i] * (mx - j + 1) * r);
			}
		}

		FOE(i,0,mx) ret = max(ret, dp[n&1^1][i]);
		mx = 0;
		FOR(i,0,n) mx = max(mx, (int)a[i]);
		ret += mx * R;
		printf("%lld\n", ret);
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
