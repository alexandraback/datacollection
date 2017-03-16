#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

//using namespace std;


int T, n, m, k;
std::pair<int, int> map[1000008];
std::pair<int, int> solve(int n, int m)
{
	return std::make_pair(n * m - 4, (n - 2) * 2 + (m - 2) * 2);
}
void work()
{
	int cnt = 0, ans = ~0u>>1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (solve(i, j).first > 0) {
				map[++cnt] = solve(i, j);
			}
		}
	}
	for (int i = 1; i <= std::max(n, m); i++) {
		map[++cnt] = std::make_pair(i, i);
	}
	sort(map + 1, map + 1 + cnt);
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= cnt; j++) {
			if (i + map[j].first >= k) {
				ans = std::min(ans, i + map[j].second);
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
