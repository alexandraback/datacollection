#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[111][111];
int v[111];
int E , R , N;
void checkmax(int &a,int b) {
	if (a == -1 || a < b) a = b;
}
int main() {
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int T , cas = 1;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d%d",&E,&R,&N);
		for (int i = 0 ; i < N ; i ++) {
			scanf("%d",&v[i]);
		}
		memset(dp , -1 , sizeof(dp));
		dp[0][E] = 0;
		int ans = 0;
		for (int i = 0 ; i < N ; i ++) {
			for (int j = 0 ; j <= E ; j ++) {
				if (dp[i][j] != -1) {
					for (int k = 0 ; k <= j ; k ++) {
						checkmax(dp[i+1][min(E , j-k+R)] , dp[i][j] + v[i] * k);
					}
				}
			}
		}
		for (int i = 0 ;  i <= E ; i ++) {
			checkmax(ans , dp[N][i]);
		}
		printf("Case #%d: %d\n" , cas ++ , ans);
	}
	return 0;
}