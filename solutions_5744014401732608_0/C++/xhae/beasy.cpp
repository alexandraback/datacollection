#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int b, m;
vector<string> ans;

bool backtr(int level) {
	if(level == b) {
		int dp[6];
		dp[b - 1] = 1;
		for(int i = b - 2; i >= 0; i--) {
			dp[i] = 0;
			for(int j = i + 1; j < b; j++)
				if(ans[i][j] == '1')
					dp[i] += dp[j];
		}
		return dp[0] == m;
	}

	int base = level + 1;
	int lim = b - level - 1;
	for(int i = 0; i < (1 << lim); i++) {
		auto v = i << base;
		ans[level] = "";
		for(int j = 0; j < b; j++) {
			if(v % 2 == 0) ans[level] += "0";
			else ans[level] += "1";
			v /= 2;
		}
		if(backtr(level + 1)) return true;
	}

	return false;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d %d", &b, &m);
		printf("Case #%d: ", kase);

		ans.resize(b);
		if(!backtr(0)) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			for(auto s: ans) printf("%s\n", s.c_str());
		}
	}
	return 0;
}