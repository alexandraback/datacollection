#include <cstdio>
#include <algorithm>

int gains[1000000];
int E, r, n;

int cache[20][10];

int maxGain(int k, int e) {
	if (k == n) return 0;
	if (cache[k][e]) return cache[k][e];

	int best = 0;
	for (int i = 0; i <= e; i++) {
		best = std::max(best, maxGain(k + 1, std::min(e - i + r, E)) + i * gains[k]);
	}

	return cache[k][e] = best;
}

void solve(int cs) {
	scanf("%d %d %d", &E, &r, &n);
	for (int i = 0; i < n; i++) scanf("%d", &gains[i]);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			cache[i][j] = 0;

	printf("Case #%d: %d\n", cs, maxGain(0, E));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}