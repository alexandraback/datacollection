#include <cstdio>

char S[101];
int count[101];

int solve() {
	for (int i = 0; S[i]; ++i) {
		count[i] = 0;
	}
	if (S[0] == '-') count[0] = 1;
	for (int i = 1; S[i]; ++i) {
		if (S[i] == '-') {
			count[i - 1]++;
			count[i]++;
		}
	}
	int res = 0;
	for (int i = 0; S[i]; ++i) {
		res += count[i] & 1;
	}
	return res;
}

int main() {
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		scanf("%s", S);
		printf("Case #%d: %d\n", tc, solve());
	}
	return 0;
}