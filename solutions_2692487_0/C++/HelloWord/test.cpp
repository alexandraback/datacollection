#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000005];
int n;
int self;
int min(int a, int b)
{
	return a < b ? a : b;
}
int dfs(int i, int size)
{
	if (i >= n)
		return 0;
	if (size > a[i]) {
		return dfs(i + 1, size + a[i]);
	} else {
		if (size == 1) {
			return n - i;
		}
		return min(dfs(i, 2 * size - 1) + 1, n - i);
	}
}
void solve()
{
	sort(a, a + n);
	printf("%d\n", dfs(0, self));
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d", &self, &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[j]);
		}
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}