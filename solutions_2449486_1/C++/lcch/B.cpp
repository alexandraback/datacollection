#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn][maxn], now[maxn][maxn];
int n, m;

void cut_r(int r, int H)
{
	bool bj = true;
	for (int j = 1; j <= m; j++)
		if (a[r][j] > H) bj = false;
	if (!bj) return;
	for (int j = 1; j <= m; j++)
		now[r][j] = min(now[r][j], H);

}

void cut_c(int c, int H)
{
	bool bj = true;
	for (int i = 1; i <= n; i++)
		if (a[i][c] > H) bj = false;
	if (!bj) return;
	for (int i = 1; i <= n; i++)
		now[i][c] = min(now[i][c], H);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int TextN, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				now[i][j] = 100;
			}
		}
		for (int H = 99; H >= 1; H--) {
			for (int i = 1; i <= n; i++) cut_r(i, H);
			for (int i = 1; i <= m; i++) cut_c(i, H);
		}
		bool ans = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (now[i][j] != a[i][j]) ans = false;
		printf("Case #%d: ", ++TT);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}