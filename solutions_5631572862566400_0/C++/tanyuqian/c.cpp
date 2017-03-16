#include <bits/stdc++.h>

const int N = 1e3 + 100;

int n;
int gay[N];

void init() {
	std::cin >> n;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &gay[i]);
	}
}

void work() {
	static int best[N][N];
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			best[i][j] = 0;
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i ++) {
		static int deep[N];
		
		std::fill(deep + 1, deep + n + 1, -1);
		
		int step = i;
		deep[i] = 1;
		while (deep[gay[step]] == -1) {
			deep[gay[step]] = deep[step] + 1;
			step = gay[step];
		}
		if (deep[gay[step]] == deep[step] - 1) {
			best[step][gay[step]] = std::max(best[step][gay[step]], deep[gay[step]]);
		}
		answer = std::max(answer, deep[step] - deep[gay[step]] + 1);
	}
	int tmp = 0;
	for (int i = 1; i <= n; i ++) {
		int j = gay[i];
		if (gay[j] == i) {
			tmp += best[i][j] + best[j][i];
		}
	}
	answer = std::max(answer, tmp / 2);
	std::cout << answer << std::endl;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c0.out", "w", stdout);
	
	int testCnt;
	std::cin >> testCnt;
	for (int i = 1; i <= testCnt; i ++) {
		printf("Case #%d: ", i);
		init();
		work();
	}
	
	return 0;
}
