#include <bits/stdc++.h>

const int INF = ~0u >> 2;

int T, answer;
std::string a, b;
std::string answerA, answerB;

void dfs(int h, int n) {
	if (h == n) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp = tmp * 10 + (a[i] - b[i]);
		}
		if (answer > std::abs(tmp)) {
			answer = std::abs(tmp);
			answerA = a;
			answerB = b;
		} else if (answer == std::abs(tmp)) {
			if (answerA > a) {
				answerA = a;
				answerB = b;
			} else if (answerA == a && answerB > b) {
				answerB = b;
			}
		}
		return;
	}
	if (a[h] == '?' && b[h] == '?') {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				a[h] = '0' + i;
				b[h] = '0' + j;
				dfs(h + 1, n);
				a[h] = '?';
				b[h] = '?';
			}
	} else if (a[h] == '?') {
		for (int i = 0; i < 10; i++) {
			a[h] = '0' + i;
			dfs(h + 1, n);
			a[h] = '?';
		}
	} else if (b[h] == '?') {
		for (int i = 0; i < 10; i++) {
			b[h] = '0' + i;
			dfs(h + 1, n);
			b[h] = '?';
		}
	} else dfs(h + 1, n);
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		std::cin >> a >> b;
		answer = INF;
		dfs(0, (int)a.length());
		printf("Case #%d: ", cs);
		std::cout << answerA << " " << answerB << std::endl;
	}
	return 0;
}
