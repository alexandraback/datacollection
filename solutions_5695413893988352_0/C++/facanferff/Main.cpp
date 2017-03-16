#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

char c[20];
char j[20];
int len;

int ans_c;
int ans_j;
string str_c;
string str_j;
int best;

void solve(int i) {
	if (i >= 2 * len) {
		int cur_c = atoi(c);
		int cur_j = atoi(j);
		if (abs(cur_c - cur_j) < best) {
			ans_c = cur_c;
			ans_j = cur_j;
			best = abs(cur_c - cur_j);
			str_c = string(c);
			str_j = string(j);
		}
		else if (abs(cur_c - cur_j) == best) {
			if (cur_c < ans_c || (cur_c == ans_c && cur_j < ans_j)) {
				ans_c = cur_c;
				ans_j = cur_j;
				str_c = string(c);
				str_j = string(j);
			}
		}

		return;
	}

	if (i < len) {
		// coders
		if (c[i] != '?') solve(i + 1);
		else {
			for (int k = 0; k <= 9; k++) {
				c[i] = k + '0';
				solve(i + 1);
				c[i] = '?';
			}
		}
	}
	else {
		// jammers
		if (j[i - len] != '?') solve(i + 1);
		else {
			for (int k = 0; k <= 9; k++) {
				j[i - len] = k + '0';
				solve(i + 1);
				j[i - len] = '?';
			}
		}
	}
}

void solve() {
	len = strlen(c);

	ans_c = 1e9;
	ans_j = 1e9;
	best = 1e9;
	solve(0);

	printf("%s %s\n", str_c.c_str(), str_j.c_str());
}

int main() {
	int t;
	scanf("%d", &t);
	for (int ctest = 1; ctest <= t; ctest++) {
		scanf(" %s %s", c, j);

		printf("Case #%d: ", ctest);
		solve();
	}
	return 0;
}
