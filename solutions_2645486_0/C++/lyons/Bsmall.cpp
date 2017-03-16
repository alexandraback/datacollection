#include <iostream>
#include <cstdio>
using namespace std;

int E, R, N;
int valmax;
int v[10];

void dfs(int k, int val, int start) {
	if (k == N) {
		if (val > valmax) valmax = val;
		return ;
	}
	for (int i = 0; i <= start; ++ i) {
		dfs(k + 1, val + i * v[k], min(E, start - i + R));
	}
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	int T;
	scanf("%d", &T);
	for (int tcase = 1; tcase <= T; ++ tcase) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &v[i]);
		valmax = 0;
		dfs(0, 0, E);
		printf("Case #%d: %d\n", tcase, valmax);
	}
	return 0;
}
