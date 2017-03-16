#pragma warning(disable:4996)
#include <stdio.h>

typedef long long LL;

int T, N, J;
int digit[64];

int okay[16];
int cnt;
void back(int a) {
	if (a == N-1) {
		if (J == 0) return;
		for (int base = 2; base <= 10; base++) {
			okay[base] = -1;
			for (int r = 2; r <= 1024 ; r++) {
				int g = 0;
				bool same = true;
				for (int i = 0; i < N; i++) {
					g = g * base + digit[i];
					if (g / r > 0) same = false;
					g %= r;
				}
				if (!same && g == 0) {
					okay[base] = r;
					break;
				}
			}
			if (okay[base] == -1) {
				return;
			}
		}
		J--;
		for (int i = 0; i < N; i++) printf("%d", digit[i]);
		for (int base = 2; base <= 10; base++) printf(" %d", okay[base]);
		printf("\n");
		return;
	}
	digit[a] = 0;
	back(a + 1);
	if (J == 0) return;
	digit[a] = 1;
	back(a + 1);
	if (J == 0) return;
}
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &J);
		digit[0] = 1;
		digit[N - 1] = 1;
		printf("Case #%d:\n", tc);
		back(1);
	}
	return 0;
}