#include <cstdio>

const int MAX=2020;

int n, x, y;

double dp[MAX][MAX];

void solve(){
	int level=0, count=0, i;
	for(i=1; count+i<=n; i+=4){
		count += i;
		level++;
	}

	int remain = n-count;

	int tLevel;
	if(x <= 0) tLevel = y-x;
	else tLevel = y+x;

	tLevel = tLevel/2+1;

	int side=tLevel*2-1, require=y+1;

	if(level >= tLevel) puts("1.0");
	else if(level == tLevel-1){
		if(remain < require || x == 0) puts("0.0");
		else if(remain-side+1 >= require) puts("1.0");
		else {
			int j;
			dp[0][0] = 1;
			for(i=1; i<=remain; i++){
				if(i < side){
					dp[0][i] = dp[0][i-1]*0.5;
					dp[i][0] = dp[i-1][0]*0.5;
				}

				for(j=1; j<i; j++){
					if(j < side && i-j < side){
						if(j == side-1)
							dp[j][i-j] = dp[j-1][i-j]*0.5+dp[j][i-j-1];
						else if(i-j == side-1)
							dp[j][i-j] = dp[j-1][i-j]+dp[j][i-j-1]*0.5;
						else
							dp[j][i-j] = dp[j-1][i-j]*0.5+dp[j][i-j-1]*0.5;
					}
				}
			}

			double res=0;
			for(i=require; i<side && i<=remain; i++)
				res += dp[remain-i][i];
			printf("%lg\n", res);
		}
	} else puts("0.0");
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cc, t;
	scanf("%d", &cc);
	for(t=1; t<=cc; t++){
		printf("Case #%d: ", t);

		scanf("%d%d%d", &n, &x, &y);
		solve();
	}

	return 0;
}