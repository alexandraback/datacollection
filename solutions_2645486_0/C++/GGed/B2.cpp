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

int e, x, r, n, ret;
int dp[100][100];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d%d%d", &e, &r, &n);
	CLR(dp, 0);
	ret = 0;
	FOR(i,0,n){
		scanf("%d", &x);
		FOE(j,0,e){
			FOE(k,0,j){
				dp[i+1][min(e, j - k + r)] = max(dp[i+1][min(e, j - k + r)], dp[i][j] + k * x);
			}
		}
	}
	
	FOE(j,0,e) ret = max(ret, dp[n][j]);
	
	printf("%d\n", ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
