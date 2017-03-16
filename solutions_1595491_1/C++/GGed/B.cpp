#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc_, n, m, p, x, mn1, mn2, dp[105];

int main(){
	scanf("%d", &tc_);
	FOE(tc,1,tc_){
		scanf("%d%d%d", &n, &m, &p);
		mn1 = p + 2 * max(0, p - 1);
		mn2 = p + 2 * max(0, p - 2);
		
		CLR(dp, 0);
		FOR(i,0,n){
			scanf("%d", &x);
			for (int j=m; j>=0; j--){
				if (x >= mn2) dp[j+1] = max(dp[j+1], dp[j] + 1);
				if (x >= mn1) dp[j]++;
			}
		}

		printf("Case #%d: %d\n", tc, dp[m]);
	}
	return 0;
}
