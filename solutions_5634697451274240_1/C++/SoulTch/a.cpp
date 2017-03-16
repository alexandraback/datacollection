#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP);

using namespace std;

int TEMP;

int dp[1000][2];
char str[1000];

void solve() {
	scanf("%s", str);
	int len = strlen(str);

	dp[0][0] = (str[0] == '+');
	dp[0][1] = (str[0] == '-');
	for (int i = 1; i < len; i++) {
		if (str[i] == '+') {
			dp[i][0] = dp[i - 1][1] + 1;
			dp[i][1] = dp[i - 1][1];
		}
		else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][0] + 1;
		}
	}
	printf("%d\n", dp[len - 1][1]);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = si();
	for (int i = 0; i < N; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}