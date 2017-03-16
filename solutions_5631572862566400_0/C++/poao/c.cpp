#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MN = 1010;

using std::vector;

int T, N;

int nxt[MN];
vector<int> edge[MN];
int dp[MN], vst[MN];

int treeDP(int now, int fa) {
	dp[now] = 0;
	for(auto it=edge[now].begin(); it!=edge[now].end(); ++it) {
		if(*it != fa) {
			dp[now] = std::max(dp[now], treeDP(*it, now));
		}
	}
	dp[now] += 1;
	fprintf(stderr, ">%d: %d\n", now, dp[now]);
	return dp[now];
}

int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc) {
		scanf("%d", &N);
		for(int i=1; i<=N; ++i) {
			dp[i] = 0;
			vst[i] = 0;
			edge[i] = vector<int>();
		}
		for(int i=1; i<=N; ++i) {
			int in;
			scanf("%d", &in);
			nxt[i] = in;
			edge[in].push_back(i);
		}
		// case 1: a circle
		int case1ans = 0;
		for(int st=1; st<=N; ++st) {
			vst[st] = st;
			int now = nxt[st], count = 1;
			while(vst[now] != st) {
				vst[now] = st;
				count++;
				now = nxt[now];
			}
			if(now == st) {
				case1ans = std::max(case1ans, count);
			}
		}
		// case 2: tree DP
		int case2ans = 0;
		for(int st=1; st<=N; ++st) {
			if(dp[st] > 0) continue;

			fprintf(stderr, "%d->%d->%d\n", st, nxt[st], nxt[nxt[st]]);
			if(nxt[nxt[st]] == st) {
				fprintf(stderr, "=====st=%d\n", st);
				case2ans += (treeDP(st, nxt[st]) + treeDP(nxt[st], st));
			}
		}
		fprintf(stderr, "#%d: %d %d\n", tc, case1ans, case2ans);
		printf("Case #%d: %d\n", tc, std::max(case1ans, case2ans));
	}
}