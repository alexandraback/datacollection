#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define min(x, y)((x) < (y) ? (x) : (y))
#define max(x, y)((x) > (y) ? (x) : (y))
const int MAX = 110;
struct node{
	long long id, len;
}pA[MAX], pB[MAX];
long long sum[MAX][MAX], dp[MAX][MAX], D[MAX][MAX], up[MAX][MAX];

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int N, M, T;
	scanf("%d", &T);
	for(int t = 1;t <= T; ++ t)
	{
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		memset(up, 0, sizeof(up));
		memset(D, 0, sizeof(D));
		scanf("%d%d", &N, &M);
		for(int i = 1;i <= N; ++ i)
			scanf("%lld%lld", &pA[i].len, &pA[i].id);
		for(int i = 1;i <= M; ++ i)
			scanf("%lld%lld", &pB[i].len, &pB[i].id);
		for(int i = 1;i <= N; ++ i)
			for(int j = 1;j <= M; ++ j){
				sum[pA[i].id][j] = sum[pA[i].id][j - 1];
				if(pA[i].id == pB[j].id){
					sum[pA[i].id][j] += pB[j].len;
				}
			}
		for(int i = 1;i <= N; ++ i)
			for(int j = 1;j <= M; ++ j){
				dp[i][j] = dp[i - 1][j];
				D[i][j] = D[i - 1][j];
				up[i][j] = up[i - 1][j];
				for(int k = 1;k <= j; ++ k){
					long long dd = 0, temp = sum[pA[i].id][j] - sum[pA[i].id][k - 1];
					if(D[i - 1][k - 1] == pA[i].id)
						temp += up[i - 1][k - 1];
					if(temp > pA[i].len)
						dd = temp - pA[i].len;
					temp = dp[i - 1][k - 1] + min(temp, pA[i].len);
					if(temp > dp[i][j]){
						dp[i][j] = temp;
						D[i][j] = pA[i].id;
						up[i][j] = dd;
					}
				}
			}
		printf("Case #%d: %lld\n", t, dp[N][M]);
	}
}