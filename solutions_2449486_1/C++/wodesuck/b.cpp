#include <stdio.h>
#include <string.h>

int n, m;
const int MAXN = 100, MAXM = 100, HEIGHT = 100;
int a[MAXN][MAXM];
bool r[MAXN], c[MAXM];

bool chk(int h)
{
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > h) r[i] = c[j] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] <= h && r[i] && c[j]) return false;
		}
	}
	return true;
}

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

void solve()
{
	for (int i = HEIGHT; i > 0; --i) {
		if (!chk(i)) { puts("NO"); return; }
	}
	puts("YES");
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		init();
		printf("Case #%d: ", k);
		solve();
	}
}
