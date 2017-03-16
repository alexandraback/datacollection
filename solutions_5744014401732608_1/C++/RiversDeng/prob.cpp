#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long i64;
const int N = 1e2;

int n, a[N][N];
i64 m;

int main() {

	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; ++i) {
		printf("Case #%d: ", i);
		scanf("%d%lld", &n, &m);
		memset(a, 0, sizeof a);
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				a[i][j] = 1;
		for (int i = n - 1; i; --i) {
			i64 c = 1;
			if (i > 1) 
				c = 1 << (i - 2);
			if (m >= c) {
				a[i][n] = 1;
				m -= c;
			}
		}
		if (m)
			puts("IMPOSSIBLE");
		else {
			puts("POSSIBLE");
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j)
					printf("%d", a[i][j]);
				puts("");
			}
		}
	}

	return 0;
}
