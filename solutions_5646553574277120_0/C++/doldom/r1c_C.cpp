#include <cstdio>
#include <vector>
using namespace std;

int c, d, v, coins[100];

int main() {
	freopen("r1c\\C-small-attempt0.in", "r", stdin);
	freopen("r1c\\C-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &c, &d, &v);
		for (int i=0; i<d; ++i)
			scanf("%d", coins+i);
		vector<bool> dp(v+1);
		dp[0] = true;
		for (int i=0; i<d; ++i) {
			vector<bool> ndp(dp);
			for (int j=0; j<=v; ++j)
				if (dp[j] && j+coins[i] <= v)
					ndp[j+coins[i]] = true;
			dp = ndp;
		}
		int ans = 0;
		while (true) {
			int smallest = -1;
			for (int i=0; i<=v; ++i)
				if (!dp[i]) {
					smallest = i;
					break;
				}
			if (smallest == -1) break;
			vector<bool> ndp(dp);
			for (int j=0; j<=v; ++j)
				if (dp[j] && j+smallest <= v)
					ndp[j+smallest] = true;
			dp = ndp;
			++ans;
		}
		printf("Case #%d: ", N);
		printf("%d\n", ans);
	}
}