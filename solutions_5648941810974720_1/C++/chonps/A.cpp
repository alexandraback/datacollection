#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

std::string digits[13] = {"ZERO", "WTO", "XSI", "GEIHT", "THREE", "RFOU", "FIVE", "VSEEN", "ONE", "INNE"};
int dig[13] = {0, 2, 6, 8, 3, 4, 5, 7, 1, 9};
char s[2333];
bool f[2333][23];

int cnt[233];
int tot[23];

int main() {
	int T;
	scanf("%d", &T);
	for (int Cases = 1; Cases <= T; ++Cases) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		for (int i = 0; i < 26; ++i) cnt[i] = 0;
		for (int i = 1; i <= n; ++i)
			++cnt[s[i] - 'A'];
		for (int i = 0; i <= 9; ++i) tot[i] = 0;
		for (int i = 0; i <= 9; ++i) {
			while (cnt[digits[i][0] - 'A']) {
				++tot[dig[i]];
				for (int j = 0; j < (int)digits[i].size(); ++j)
					--cnt[digits[i][j] - 'A'];
			}
		}
		printf("Case #%d: ", Cases);
		for (int i = 0; i <= 9; ++i)
			for (int j = 0; j < tot[i]; ++j)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}
