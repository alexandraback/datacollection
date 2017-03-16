#include <stdio.h>
#include <string.h>

const int R = 100, N = 3, M = 5, K = 7;
int a[N], b[K];
bool t[M * M * M + 1];

bool chk()
{
	memset(t, 0, sizeof(t));
	t[1] = true;
	for (int i = 0; i < N; ++i) {
		for (int j = M * M * M; j >= 1; --j) {
			if (t[j] && a[i] * j <= M * M * M)
				t[a[i] * j] = true;
		}
	}
	for (int i = 0; i < K; ++i) if (!t[b[i]]) return false;
	return true;
}

void solve()
{
	for (a[0] = 2; a[0] <= M; ++a[0]) {
		for (a[1] = 2; a[1] <= M; ++a[1]) {
			for (a[2] = 2; a[2] <= M; ++a[2]) {
				if (chk()) {
					printf("%d%d%d\n", a[0], a[1], a[2]);
					return;
				}
			}
		}
	}
	puts("222");
}

int main()
{
	puts("Case #1:");
	int tmp;
	scanf("%d%d%d%d%d", &tmp, &tmp, &tmp, &tmp, &tmp);
	for (int tmp = 0; tmp < R; ++tmp) {
		for (int i = 0; i < K; ++i) scanf("%d", &b[i]);
		solve();
	}
}
