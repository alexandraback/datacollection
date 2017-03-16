#include <cstdio>

const int INF = 2147483647;
inline int min(int a, int b) { return a < b?a : b;}

int mul[8][8] = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 0, 3, 2, 5, 4, 7, 6},
	{2, 3, 1, 0, 6, 7, 5, 4},
	{3, 2, 0, 1, 7, 6, 4, 5},
	{4, 5, 7, 6, 1, 0, 2, 3},
	{5, 4, 6, 7, 0, 1, 3, 2},
	{6, 7, 4, 5, 3, 2, 1, 0},
	{7, 6, 5, 4, 2, 3, 0, 1}
};
long long L, X;
char str[10005];
int prefix[10005];
int suffix[10005];
int all[4];

int toId(char c) {
	return (c - 'i') * 2 + 2;
}

void calcPrefix() {
	prefix[0] = 0;
	for (int i = 1; i <= L; ++i) {
		int tmp = toId(str[i - 1]);
		prefix[i] = mul[prefix[i - 1]][tmp];
	}
}

void calcSuffix() {
	suffix[L] = 0;
	for (int i = L - 1; i >= 0; --i) {
		int tmp = toId(str[i]);
		suffix[i] = mul[tmp][suffix[i + 1]];
	}
}

void calcAll() {
	all[0] = 0;
	all[1] = prefix[L];
	all[2] = mul[all[1]][all[1]];
	all[3] = mul[all[2]][all[1]];
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%lld%lld", &L, &X);
		scanf("%s", str);
		calcPrefix();
		calcSuffix();
		calcAll();
		bool valid = true;
		if (all[X % 4] != 1) valid = false;
		else {
			int minPrefix = INF;
			for (int i = 0; i <= L; ++i) {
				for (int j = 0; j < 4; ++j) {
					if (mul[all[j]][prefix[i]] == 2) {
						minPrefix = min(minPrefix, j * L + i);
					}
				}
			}
			int minSuffix = INF;
			for (int i = 0; i <= L; ++i) {
				for (int j = 0; j < 4; ++j) {
					if (mul[suffix[L - i]][all[j]] == 6) {
						minSuffix = min(minSuffix, j * L + i);
					}
				}
			}
			//printf("%d %d\n", minPrefix, minSuffix);
			if (minSuffix == INF || minPrefix == INF) valid = false;
			else if (minSuffix + minPrefix > L * X) valid = false;
		//printf("Case #%d: %s\n", t, valid?"YES":"NO");
		}
		//printf("-- %d\n", all[X % 4]);
		printf("Case #%d: %s\n", t, valid?"YES":"NO");
	}
}