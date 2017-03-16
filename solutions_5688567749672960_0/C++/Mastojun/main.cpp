#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int N;
int dp[1000100];
int result;

int rev(int num) {
	int result = 0;
	while(num) {
		result *= 10;
		result += num%10;
		num /= 10;
	}

	return result;
}

int solve() {
	dp[1] = 1;

	for(int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		int revNumber = rev(i);
		if(i % 10 && revNumber < i) dp[i] = min(dp[i], dp[revNumber] + 1);
	}

	return dp[N];
}

int main() {

	scanf("%d", &T);
	
	for(int Case = 1; Case <= T; Case++) {
		scanf("%d", &N);
		memset(dp, -1, sizeof(dp));
		result = INT_MAX;
		printf("Case #%d: %d\n", Case, solve());
	}

	return 0;
}
