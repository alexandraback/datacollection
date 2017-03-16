#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

#define MAXN 20
#define MAXKEY 420

typedef long long lint;

using namespace std;

int needfor[MAXN], ntreasure[MAXN], treasure[MAXN][MAXKEY];
int dp[1<<MAXN];

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int k, n;
		vector <int> init;

		scanf("%d %d", &k, &n);
		
		for (int i = 0; i < k; i++) {
			int key;
			scanf("%d", &key);
			init.push_back(key);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &needfor[i]);
			scanf("%d", &ntreasure[i]);
			for (int j = 0; j < ntreasure[i]; j++)
				scanf("%d", &treasure[i][j]);
		}

		dp[(1<<n)-1] = -2;
		for (int s = (1<<n)-2; s >= 0; s--) {
			map <int, int> amount;
			for (int i = 0; i < init.size(); i++)
				amount[init[i]] ++;
			for (int i = 0; i < n; i++)
				if (s & (1<<i)) {
					amount[needfor[i]] --;
					for (int j = 0; j < ntreasure[i]; j++)
						amount[treasure[i][j]] ++;
				}

			dp[s] = -1;

			for (int i = 0; i < n; i++)
				if (!(s & (1<<i)) && amount[needfor[i]] > 0) {
					if (dp[s | (1<<i)] != -1) {
						dp[s] = i;
						break;
					}
				}
		}

		printf("Case #%d:", t+1);
		if (dp[0] == -1)
			printf(" IMPOSSIBLE\n");
		else {
			int s = 0;
			for (int i = 0; i < n; i++) {
				printf(" %d", dp[s]+1);
				s = s | (1<<dp[s]);
			}
			printf("\n");
		}
	}

	return 0;
}
