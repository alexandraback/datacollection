#include <cstdio>
#include <algorithm>
using namespace std;

int T, i, j, ans1, n, ans2;
double a[1100], b[1100];
bool used[1100];

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int Q = 1; Q <= T; Q++) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)	scanf("%lf", &a[i]);
		for (i = 1; i <= n; i++)	scanf("%lf", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for (i = 1; i <= n; i++)	used[i] = false;
		for (ans1 = 0, i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)	if (!used[j] && b[j] > a[i])	break;
			if (j <= n)	used[j] = true;
			else	ans1++;
		}
		for (i = 1; i <= n; i++)	used[i] = false;
		for (ans2 = 0, i = 1; i <= n; i++) {
			for (j = n; j; j--)	if (!used[j] && a[i] > b[j])	break;
			if (j)	used[j] = true, ans2++;
		}
		printf("Case #%d: %d %d\n", Q, ans2, ans1);
	}
}
