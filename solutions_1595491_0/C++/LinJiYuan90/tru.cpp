#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <string>

using namespace std;

int max_score_2apart[100];
int max_score_normal[100];

void init()
{
	for (int a = 0; a <= 10; a ++) {
		if (a >= 2){
			max_score_2apart[a+a+(a-2)] = max(max_score_2apart[a+a+(a-2)], a);
			max_score_2apart[a+(a-1)+(a-2)] = max(max_score_2apart[a+(a-1)+(a-2)], a);
			max_score_2apart[a+(a-2)+(a-2)] = max(max_score_2apart[a+(a-2)+(a-2)], a);
		}
		max_score_normal[a+a+a] = max(max_score_normal[a+a+a], a);
		max_score_normal[a+a+(a-1)] = max(max_score_normal[a+a+(a-1)], a);
		max_score_normal[a+(a-1)+(a-1)] = max(max_score_normal[a+(a-1)+(a-1)], a);
	}
}

int main()
{

	init();
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t = 1;
	for (scanf("%d", &T) ;T--; ) {
		printf("Case #%d: ", t++);
		int n, s, p, score[110];
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &score[i]);
		}
		int dp[110][110];
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) {
			dp[0][i] = dp[0][i-1] + (max_score_normal[score[i]] >= p);
		}
		for (int k = 1; k <= s; k++) {
			dp[k][0] = -1000000;
			for (int i = 1; i <= n; i++) {
				dp[k][i] = max(dp[k-1][i-1] + (max_score_2apart[score[i]] >= p), dp[k][i-1] + (max_score_normal[score[i]] >= p));
			}
		}
		printf("%d\n", dp[s][n]);
	}
	return 0;
}
