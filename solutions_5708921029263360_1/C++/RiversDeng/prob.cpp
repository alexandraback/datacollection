#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long i64;
const int N = 1e3 + 10;

int a, b, c, k;

int main() {

	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; ++i) {
		printf("Case #%d: ", i);
		scanf("%d%d%d%d", &a, &b, &c, &k);
		int ans = a * b * min(c, k);
		printf("%d\n", ans);
		for (int x = 1; x <= a; ++x)
			for (int y = 1; y <= b; ++y)
				for (int z = 1; z <= min(c, k); ++z)
					printf("%d %d %d\n", x, y, (x + y + z) % c + 1);
	}

	return 0;
}
