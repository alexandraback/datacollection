#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

int A, ans, n;
int a[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		if (t == 4)
			t = 4;
		scanf("%d %d", &A, &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		ans = n;
		int cnt = 0;
		if (A != 1)
		{
			for(int i = 1; i <= n; i++)
			{
				if (A > a[i])
					A += a[i];
				else
				{
					ans = min(ans, cnt + n - i + 1);
					A += A - 1;
					i--;
					cnt++;
				}
			}
			ans = min(ans, cnt);
		}
		//ans = min(ans, i + n - stop);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
