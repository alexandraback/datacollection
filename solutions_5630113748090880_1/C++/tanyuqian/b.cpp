#include <bits/stdc++.h>

void work() {
	static bool count[5100];
	
	std::fill(count, count + 3000, false);
	
	int n;
	std::cin >> n;
	for (int i = 1; i <= 2 * n - 1; i ++) {
		for (int j = 1; j <= n; j ++) {
			int t;
			scanf("%d", &t);
			count[t] ^= true;
		}
	}
	std::vector<int> answer;
	for (int i = 1; i <= 2500; i ++) {
		if (count[i]) {
			answer.push_back(i);
		}
	}
	for (int i = 0; i < (int)answer.size(); i ++) {
		printf("%d%c", answer[i], " \n"[i + 1 == (int)answer.size()]);
	}
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b1.out", "w", stdout);
	
	int testCnt;
	std::cin >> testCnt;
	for (int i = 1; i <= testCnt; i ++) {
		printf("Case #%d: ", i);
		work();
	}
	
	return 0;
}
