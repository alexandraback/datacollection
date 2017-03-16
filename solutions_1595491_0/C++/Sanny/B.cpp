#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define rep(i,n) for(i=0;i<(n);i++)
#define MAXN 105

int mx[35][2];

void init() {
	int i, j, k, l;
	memset(mx, -1, sizeof(mx));
	for(i=0;i<=30;i++) {
		for(j = 0; j <= 10; j++) {
			for(k = j; k <= 10; k++) {
				if(k > j+2) break;
				for(l = k; l <= 10; l++) {
					if(l > j+2) break;
					if(j + k + l == i) {
						if(l == j+2) mx[i][1] = max(mx[i][1], l);
						else mx[i][0] = max(mx[i][0], l);
					}
				}
			}
		}
	}
}
int N, S, p;
int t[MAXN];
int dp[MAXN][MAXN];

void solve() {
	int i, j;
	memset(dp, 0, sizeof(dp));
	if(mx[t[0]][0] >= p) dp[0][0] = 1;
	if(mx[t[0]][1] >= p) dp[0][1] = 1;
	for(i=1;i<N;i++) {
		for(j=0;j<=i;j++) {
			if(mx[t[i]][0] > -1) dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(mx[t[i]][1] > -1) dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]);

			if(mx[t[i]][0] >= p) {
				dp[i][j] = max(dp[i][j], dp[i-1][j]+1 );
			}
			if(mx[t[i]][1] >= p) {
				dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]+1 );
			}
			
		}
	}
	printf("%d\n", dp[N-1][S]);
}

int main() {
	int T, kase = 1;
	int i;
	scanf(" %d",&T);
	init();
	while(T--) {
		printf("Case #%d: ", kase++);
		scanf(" %d %d %d",&N, &S, &p);
		rep(i, N) scanf(" %d",&t[i]);
		solve();
	}
	return 0;
}