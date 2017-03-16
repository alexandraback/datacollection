#include <bits/stdc++.h>

const int MAXN = 2001;
const std::string str[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const int p[] = {0, 2, 8, 3, 4, 1, 6, 7, 5, 9};
const char d[] = "ZWGTROXSVI";

int T, cnt[2006], answer[11];
char s[1001];

void reduce(int x, int v) {
	int len = str[x].length();
	for (int i = 0; i < len; i++) {
		cnt[str[x][i]] -= v;
	}
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		std::fill(cnt, cnt + 1000, 0);
		std::fill(answer, answer + 10, 0);
		for (int i = 1; i <= n; i++) cnt[s[i]]++;
		for (int i = 0; i < 10; i++) {
			int tmp = cnt[d[i]];
			answer[p[i]] = tmp;
			reduce(p[i], tmp);
		}
		printf("Case #%d: ", cs);
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j <= answer[i]; j++)
				printf("%d", i);
		}
		puts("");
	}
	return 0;
}
