#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[1000001], n, p, s, ans;
bool cmp(int a, int b) { return a > b; }
int main()
{
freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
int T; scanf("%d", &T);	
for (int Ti = 1; Ti <= T; Ti++){
	scanf("%d%d%d", &n, &s, &p);
	ans = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		if (a[i] >= 3 * p - 2) { ++ans; continue; }
		if (a[i] >= max(3 * p - 4, p) && s > 0) { ++ans; --s; continue; }	
	}
	printf("Case #%d: %d\n", Ti, ans);
}
}
