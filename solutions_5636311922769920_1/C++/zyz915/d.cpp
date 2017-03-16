#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

long long pws[120];

void run(int cas) {
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
	if (k > c * s) {
		printf("Case #%d: IMPOSSIBLE\n", cas);
		return;
	}
	int i, j;
	pws[0] = 1;
	for (i = 1; i < c; i++)
		pws[i] = pws[i - 1] * k;
	printf("Case #%d:", cas);
	for (i = 0; i < k; i += j) {
		long long val = 0;
		for (j = 0; j < c; j++)
			val += pws[j] * std::min(i + j, k - 1);
		printf(" %lld", val + 1);
	}
	printf("\n");
}

int main() {
	int cas, tt;
	scanf("%d", &tt);
	for (cas = 1; cas <= tt; cas++)
		run(cas);
	return 0;
}

