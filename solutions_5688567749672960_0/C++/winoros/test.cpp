#include <bits/stdc++.h>

int dp[1000010];

void MAIN() {
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 1;
	for(int i = 1; i < 30; ++i) {
		std::string tmp = std::to_string(i);
		std::reverse(tmp.begin(), tmp.end());
		int reverse = std::stoi(tmp);
		dp[i+1] = std::min(dp[i+1], dp[i] + 1);
		dp[reverse] = std::min(dp[reverse], dp[i] + 1);
	}
}

int main() {
	MAIN();
	int n;
	scanf("%d", &n);
	while(n--) {
		int num;
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}
	return 0;
}

