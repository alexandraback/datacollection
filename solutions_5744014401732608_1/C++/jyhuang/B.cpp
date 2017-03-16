// Problem B. Slides!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int b;
		long long m;
		scanf("%d %lld", &b, &m);

		long long mx = (1LL << (b - 2));

		if (m > mx) {
			printf("Case #%d: IMPOSSIBLE\n", ti);
			continue;
		}

		printf("Case #%d: POSSIBLE\n", ti);

		if (m == mx) {
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++)
					printf("%d", j > i ? 1 : 0);
				printf("\n");
			}
		} else {
			vector<bool> a(b);
			for (int k = 0; (1LL << k) <= m; k++)
				if (m & (1LL << k)) a[b - k - 2] = true;
			for (int i = 0; i < b; i++)
				printf("%d", a[i] ? 1 : 0);
			printf("\n");
			for (int i = 1; i < b; i++) {
				for (int j = 0; j < b; j++)
					printf("%d", j > i ? 1 : 0);
				printf("\n");
			}
		}

	}

	return 0;
}
