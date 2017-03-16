#include <stdio.h>

//#define min(a,b) a<b?(a):(b)
//#define max(a,b) a>b?(a):(b)

long long min(long long a, long long b){
	if(a < b)
		return a;
	else
		return b;
}

long long max(long long a, long long b){
	if(a > b)
		return a;
	else
		return b;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int tt=0; tt<t; tt++){
		int n, m;
		scanf("%d%d", &n, &m);
		long long a[n], b[m];
		int A[n], B[m];
		for(int i=0; i<n; i++)
			scanf("%lld%d", a+i, A+i);
		for(int i=0; i<m; i++)
			scanf("%lld%d", b+i, B+i);
		long long dp[n+1][m+1];
		for(int i=0; i<n+1; i++)
			dp[i][0] = 0;
		for(int j=0; j<m+1; j++)
			dp[0][j] = 0;
		for(int i=1; i<n+1; i++){
			for(int j=1; j<m+1; j++){
				int sw, target;
				long long tmp1 = 0LL, tmp2 = 0LL, total, rest;
				int ii, jj;
				ii = i-1;
				jj = j-1;
				sw = 1;
				target = A[ii];
				total = 0LL;
				rest = a[ii];
				while(ii >= 0 && jj >= 0){
//					printf("sw=%d ii=%d jj=%d\n", sw, ii, jj);
					if(sw){
						if(B[jj] == target){
							total += min(rest, b[jj]);
							tmp1 = max(tmp1, dp[ii][jj]+total);
							if(rest < b[jj]){
								sw = 0;
								rest = b[jj]-rest;
								ii--;
							}else{
								rest -= b[jj];
								jj--;
							}
						}else
							jj--;
					}else{
						if(A[ii] == target){
							total += min(rest, a[ii]);
							tmp1 = max(tmp1, dp[ii][jj]+total);
							if(rest < a[ii]){
								sw = 1;
								rest = a[ii]-rest;
								jj--;
							}else{
								rest -= a[ii];
								ii--;
							}
						}else
							ii--;
					}
				}
				ii = i-1;
				jj = j-1;
				sw = 0;
				target = B[jj];
				total = 0LL;
				rest = b[jj];
				while(ii >= 0 && jj >= 0){
//					printf("sw=%d ii=%d jj=%d\n", sw, ii, jj);
					if(sw){
						if(B[jj] == target){
							total += min(rest, b[jj]);
							tmp2 = max(tmp2, dp[ii][jj]+total);
							if(rest < b[jj]){
								sw = 0;
								rest = b[jj]-rest;
								ii--;
							}else{
								rest -= b[jj];
								jj--;
							}
						}else
							jj--;
					}else{
						if(A[ii] == target){
							total += min(rest, a[ii]);
							tmp2 = max(tmp2, dp[ii][jj]+total);
							if(rest < a[ii]){
								sw = 1;
								rest = a[ii]-rest;
								jj--;
							}else{
								rest -= a[ii];
								ii--;
							}
						}else
							ii--;
					}
				}
/*				
				int k = j-1;
				while(k >= 0 && B[k] != A[i-1])
					k--;
//				printf("k=%d\n", k);
				if(k < 0)
					tmp1 = 0;
				else{
					tmp1 = dp[i-1][k]+min(a[i-1], b[k]);
//					printf("tmp1=%d+%d\n", dp[i-1][k], min(a[i-1], b[k]));
				}
				k = i-1;
				while(k >= 0 && A[k] != B[j-1])
					k--;
//				printf("k=%d\n", k);
				if(k < 0)
					tmp2 = 0;
				else{
					tmp2 = dp[k][j-1]+min(a[k], b[j-1]);
//					printf("tmp2=%d+%d\n", dp[k][j-1], min(a[k], b[j-1]));
				}
//				printf("max(tmp1,tmp2)=%d dp[i-1][j-1]=%d\n", max(tmp1, tmp2), dp[i-1][j-1]);*/
				dp[i][j] = max(max(tmp1, tmp2), dp[i-1][j-1]);
//				printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
			}
		}
		printf("Case #%d: %lld\n", tt+1, dp[n][m]);
	}
	return 0;
}
