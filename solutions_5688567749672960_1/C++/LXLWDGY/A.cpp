#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n, ans;
char s[21];
int Q[15];

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	for (int i = 2, j = 1; i <= 14; ++i) {
		if (i % 2 == 0) {
			Q[i] = Q[i - 1] + j * 10 + j - 1;
			j *= 10;
		}
		else {
			Q[i] = Q[i - 1] + j * 2 - 1;
		}
	}
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT) {
		ans = 0;
		scanf("%s", s);
		n = strlen(s);
		if (n == 1) {
			printf("Case #%d: %c\n", TT, s[0]);
			continue;
		}
		if (s[n - 1] == '0') {
			int k;
			for (k = n - 1; s[k] == '0' && k > 0; --k) s[k] = '9';
			if (k == 0 && s[0] == '1') {
				printf("Case #%d: %d\n", TT, Q[n]);
				continue;
			}
			--s[k];
			++ans;
		}
		int i, j;
		for (i = 0, j = 1; i < n / 2; ++i, j *= 10) ans += (s[i] - '0' + s[n - i - 1] - '0') * j;
		if (n % 2 == 1) ans += (s[n / 2] - '0') * j;
		bool del = true;
		for (i = 1; i < n / 2; ++i) if (s[i] != '0') del = 0;
		if (s[0] == '1' && del) --ans;
		printf("Case #%d: %I64d\n", TT, ans + Q[n]);
	}
	return 0;
}
