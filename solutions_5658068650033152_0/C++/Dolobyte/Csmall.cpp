#include<cstdio>
#include<cstring>

int T, N, M, K;
int dp[25][25][25][405];

bool ins(int x){
	return x>=1 && x<=M;
}

void work(int i, int l, int r, int rest){
	if (rest == r-l+1){
		dp[i][l][r][rest] = r-l+1;
		return;
	}
	if (i > N || rest < 0){
		dp[i][l][r][rest] = 1000;
		return;
	}
	int ret = 0x7fffffff;
	for(int d1=-1; d1<=1; d1++)
		for(int d2=-1; d2<=1; d2++){
			int nl = l + d1, nr = r + d2;
			if (nl <= nr && nl <= r && nr >= l && ins(nl) && ins(nr)){
				if (dp[i][nl][nr][rest-(r-l+1)] == -1)
					work(i,nl,nr,rest-(r-l+1));
				if (ret > dp[i][nl][nr][rest-(r-l+1)])
					ret = dp[i][nl][nr][rest-(r-l+1)];
			}
		}
	dp[i][l][r][rest] = ret + (l==r? 1 : 2);
}

int main(){
	freopen("Cs.in", "r", stdin);
freopen("C.out", "w", stdout);
	 scanf("%d", &T);
	for(int O=1; O<=T; O++){
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &N, &M, &K);

		if (N == 1 || M == 1){
			printf("Case #%d: %d\n", O, K);
			continue;
		}
		int ans = 0x7fffffff;
		for(int i=1; i<=M; i++)
			for(int j=i; j<=M; j++){
				if (dp[1][i][j][K] == -1) work(1, i, j, K);
				int tp = (i==j)? 0 : j-i-1;
				if (ans > dp[1][i][j][K]+tp) ans = dp[1][i][j][K]+tp;
			}
		printf("Case #%d: %d\n", O, ans);
	}
	fclose(stdout);
	return 0;
}
