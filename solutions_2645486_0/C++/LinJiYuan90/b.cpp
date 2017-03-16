#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

int dp[2][100];

int main()
{
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		int E, R, N;
		scanf("%d%d%d", &E, &R, &N);
		int pre = 0, next = 1;
		fill(dp[pre], dp[pre]+E+1, -1);
		dp[pre][E] = 0;
		for (int i = 0, v; i < N; i++) {
			scanf("%d", &v);
			fill(dp[next], dp[next] + E + 1, -1);
			for (int e = E; e >= 0; e--) {
				if (dp[pre][e] >= 0) {
					for (int s = 0; s <= e; s++) {
						int &ans = dp[next][min(E, e - s + R)];
						ans = max(ans, dp[pre][e] + v*s);
					}
				}
			}
			swap(pre, next);
		}
		printf("%d\n", *max_element(dp[pre], dp[pre] + E+1));
	}
	return 0;
}


