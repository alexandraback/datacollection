#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int t;
int a, n;
int siz[Maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &a, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &siz[i]);
		if (a == 1) printf("Case #%d: %d\n", tc, n);
		else {
			sort(siz, siz + n);
			int cur = 0, res = n;
			for (int i = 0; i < n; i++)
				if (a > siz[i]) a += siz[i];
				else {
					res = min(res, cur + n - i);
					a += a - 1; cur++; i--;
				}
			res = min(res, cur);
			printf("Case #%d: %d\n", tc, res);
		}
	}
	return 0;
}