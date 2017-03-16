/*************************************************************************
    > File Name: C-large.cpp
    > Created Time: 日  5/ 6 18:30:33 2012
 ************************************************************************/

#include<iostream>
using namespace std;

long long A[128][2], B[128][2];
long long dp[128][128];

int main() {
	int Ncase;
	cin >> Ncase;
	for(int T = 1; T <= Ncase; T ++) {
		int n, m;
		long long ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) {
			cin >> A[i][1] >> A[i][0];
		}
		for(int i = 1; i <= m; i ++) {
			cin >> B[i][1] >> B[i][0];
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0]=0;
		for(int i = 0; i <= n; i ++)
			for(int j = 0; j <= m; j ++) {
				long long cur = dp[i][j];
				long long K = A[i + 1][0];
				long long sum = 0, sum2 = 0;
				int p = j + 1, lastk = i;
				if(ans <= cur) ans = cur;
				if(dp[i + 1][j] <= cur) dp[i + 1][j] = cur;
				if(dp[i][j + 1] <= cur) dp[i][j + 1] = cur;
				for(int k = i + 1; k <= n; k ++) {
					if(A[k][0] != K) continue;
					long long temp = cur + (sum < sum2 ? sum : sum2);
					if(dp[k][p] < temp) dp[k][p] = temp;
					sum += A[k][1];
					while(sum2 < sum && p <= m) {
						while(B[p][0] != K && p <= m) {
							p ++ ;
						}
						sum2 += B[p][1];
						temp = cur + (sum < sum2 ? sum : sum2);
						if(dp[k][p] < temp) dp[k][p] = temp;
						p ++;
					}
				}
			}
		cout << "Case #" << T << ": " << ans << endl;
	}
}
