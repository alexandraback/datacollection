#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;


#define Rep(i,n) for(int i = 0; i < n; ++i)
#define Rep2(i, f, t) for(int i = (f); i <= (t); ++i)
#define tr(C,it) for(__typeof__((C).begin()) it = (C).begin(); it != (C).end(); ++it)

int dp[110];
int n, S, p;

void update(int& best, int score, int lb, int index, int isp) {
	if(isp && (index == 0))return;
	if((score < lb) || (score > 10))return;
	if(dp[index - isp] < 0)return;
	best = max(best, dp[index - isp] + (score >= p));
}

int main() {
	int T;
	scanf("%d", &T);
	for(int Case = 1; Case <= T; ++Case) {
		scanf("%d%d%d", &n, &S, &p);
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		int t;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &t);
			for(int j = S; j >= 0; --j) {
				int best = -1;
				switch(t % 3) {
					case 0:
						update(best, t / 3, 0, j, false);
						update(best, t / 3 + 1, 2, j, true);
						break;

					case 1:
						update(best, t / 3 + 1, 1, j, false);
						update(best, t / 3 + 1, 2, j, true);
						break;

					case 2:
						update(best, t / 3 + 1, 1, j, false);
						update(best, t / 3 + 2, 2, j, true);
						break;
				}
				dp[j] = best;
			}
		}	
		printf("Case #%d: %d\n", Case, dp[S]);
	}

	return 0;
}

