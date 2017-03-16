#include <bits/stdc++.h>
using namespace std;
int dp[1000010];

void fnc() {
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 1;
	for(int i = 1; i < 1000000; ++i) {
		string tmp = std::to_string(i);
		reverse(tmp.begin(), tmp.end());
		int reverse = stoi(tmp);
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		dp[reverse] = min(dp[reverse], dp[i] + 1);
	}
}

int main() {
	fnc();
	int n;
	scanf("%d", &n);
	int cas = 1;
	while(n--) {
		int num;
		scanf("%d", &num);
		printf("Case #%d: %d\n", cas++, dp[num]);
	}
	return 0;
}

