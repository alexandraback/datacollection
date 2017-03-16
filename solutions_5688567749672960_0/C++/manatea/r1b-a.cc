#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int T;
int N;
const int MAX_N = 1000000;
int dp[MAX_N];

int reverseInt(int num)
{
	char buf[32];
	if (num % 10 == 0) {
		return MAX_N + 1;
	}
	sprintf(buf, "%d", num);
	int len = strlen(buf);
	int imax = len / 2;
	for (int i = 0; i < imax; ++i) {
		swap(buf[i], buf[len-1-i]);
	}
	int ret = atoi(buf);
	return ret;
}

void solve()
{
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	for (int i = 1; i < N; ++i) {
		int rev = reverseInt(i+1);
		if (rev < i+1) {
			dp[i+1] = min(dp[i] + 1, dp[rev] + 1);
		} else {
			dp[i+1] = dp[i] + 1;
		}
	}
	// for (int i = 1; i< N; ++i) printf("%d ", dp[i]);
	printf("%d", dp[N]);
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
	return 0;
}
