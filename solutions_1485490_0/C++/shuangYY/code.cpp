#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long A[101][2];
long long B[101][2];
long long dp[101][101];

int cases = 0;
int T;
int n, m;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	while(cases < T){
		cases ++;

		scanf("%d%d", &n, &m);
		for(int i=1; i<=n;i++)
			scanf("%lld%lld", &A[i][0], &A[i][1]);
		for(int i=1; i<=m; i++)
			scanf("%lld%lld", &B[i][0], &B[i][1]);

		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){

				if(A[i][1] != B[j][1])
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				else {
					long long tmp0 = 0, tmp1 = 0;
					for(int l=i; l>=1; l--){
						if(A[l][1] == A[i][1])
							tmp0 += A[l][0];
						tmp1 = 0;
						for(int r=j; r>=1; r--){
							if(B[r][1] == A[i][1])
								tmp1 += B[r][0];

							//if()
							dp[i][j] = max(dp[i][j], dp[l-1][r-1] + min(tmp0, tmp1));
						}
					}
				}
			}
		}
		
		printf("Case #%d: %lld\n", cases, dp[n][m]);
	}
}