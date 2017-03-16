#include <stdio.h>
#include <string.h>

int lot[4][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};

int mul(int a, int b) {
	int p = (a&4)^(b&4);
	return p^lot[a&3][b&3];
}

int l;
long long x;
char inp[3000010];

int dp[2][4][8];

int main() {
	int cas;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d%lld%s", &l, &x, inp);
		if(x > 20) x = (x - 20) % 4 + 20;
		for (int i=0; i<l; i++) inp[i] -= 'i'-1;
		for (int j=l; j<l*x; j++) inp[j] = inp[j-l];
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i=0; i<l*x; i++) {
			int il = i&1;
			memset(dp[1-il], 0, sizeof(dp[1-il]));
			for (int j=0; j<3; j++) {
				for (int k=0; k<8; k++) {
					if (dp[il][j][k]) {
						int c = mul(k, inp[i]);
						dp[1-il][j][c] = 1;
						if (c == j+1) dp[1-il][j+1][0] = 1;
					}
				}
			}
		}
		printf("Case #%d: %s\n", ii+1, dp[l*x%2][3][0] ? "YES" : "NO");
	}
	return 0;
}

