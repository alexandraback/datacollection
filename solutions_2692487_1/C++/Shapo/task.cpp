#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define maxs 1000500
#define maxn 105

using namespace std;

int n, cur;
int a[maxn];
int ok[maxn][maxs];

int proc(const int &id) {
	printf("Case #%d: ", id);
	scanf("%d%d", &cur, &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	int max_size = a[n - 1] + 100;
	for (int i = 0; i <= max_size; ++i)
		ok[0][i] = n;
	ok[0][cur] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= max_size; ++j)
			ok[i + 1][j] = n;
		for (int j = cur; j < max_size; ++j) {
			if (j <= a[i]) {
				if (j != 1) {
					int let = j, number = 0;
					while (let <= a[i]) {
						let += let - 1, ++number;
					}
					ok[i + 1][min(let + a[i], max_size)] = 
						min(ok[i + 1][min(let + a[i], max_size)], ok[i][j] + number);
				}
				ok[i + 1][j] = min(ok[i + 1][j], ok[i][j] + 1);
			} else
				ok[i + 1][min(j + a[i], max_size)] = min(ok[i + 1][min(j + a[i], max_size)], 
						ok[i][j]);
		}
		ok[i + 1][max_size] = min(ok[i + 1][max_size], ok[i][max_size]);
	}
	int ans = n;
	for (int i = cur; i <= max_size; ++i) ans = min(ans, ok[n][i]);
	printf("%d\n", ans);
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) proc(i + 1);
	return 0;
}
