#include <cstdio>
#include <cmath>

const double EPS = 1e-10;
const int MAX = 2000;


int N, X, Y;
int w, rem, rem2;
int nd;


//double cc[MAX][MAX];

double dp[MAX][MAX];
inline int min(int a, int b){ return a < b ? a : b; }

double DP(){
	//printf("w = %d, rem = %d, nd = %d\n", w, rem, nd);
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			dp[i][j] = 0.0;
	dp[0][0] = 1.0;
	for(int sum = 1; sum <= rem; sum++){
		for(int left = 0; left <= min(sum, w+1); left++){
			int right = sum - left;
			if(right > min(sum, w+1)) continue;
			dp[left][right] = 0.0;
			if(left > 0){
				if(right == w+1){
					dp[left][right] +=       dp[left - 1][right];
				}else{
					dp[left][right] += 0.5 * dp[left - 1][right];
				}
			}
			if(right > 0){
				if(left == w+1){
					dp[left][right] +=       dp[left][right - 1];
				}else{
					dp[left][right] += 0.5 * dp[left][right - 1];
				}
			}
			//printf("lr=%d, %d,   %.5lf\n", left, right, dp[left][right]);
		}
	}
	double ans = 0.0;
	for(int right = nd; right <= min(rem, w+1); right++){
		int left = rem - right;
		ans += dp[left][right];
	}
	return ans;
}

int main(){
	/*
	for(int n = 0; n < MAX; n++){
		for(int k = 0; k < MAX; k++){
			cc[n][k] = 0;
		}
		cc[n][0] = 1.0;
	}
	for(int n = 1; n < MAX; n++){
		
	}
	// */
	for(int T, t = (scanf("%d", &T), 1); t <= T; t++){
		scanf("%d %d %d", &N, &X, &Y);
		if(X < 0) X *= -1;
		
		for(w = 1; (w+2) * (w+2 + 1) / 2 <= N; w += 2);
		if(X + Y <= w-1){
			printf("Case #%d: 1.0\n", t);
		}else if(X + Y > w-1 + 2){
			printf("Case #%d: 0.0\n", t);
		}else{
			rem = N - w * (w + 1) / 2;
			if(rem > w+1){
				if(Y > w+1 - 1){
					printf("Case #%d: 0.0\n", t);
				}else{
					rem2 = rem - (w+1);
					nd = Y + 1;
					printf("Case #%d: %.9lf\n", t, DP());
				}
			}else{
				if(Y > rem - 1){
					printf("Case #%d: 0.0\n", t);
				}else{
					nd = Y + 1;
					printf("Case #%d: %.9lf\n", t, DP());
				}
			}
		}
	}
	return 0;
}
