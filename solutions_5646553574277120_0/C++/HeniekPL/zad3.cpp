#include <cstdio>
#include <cstdlib>

using namespace std;

const int V_MAX = 31;
int dane[V_MAX];

void add(int v, int k) {
	for (int j = v; j >= 0; --j) {
		if (j + k <= v && dane[j] == 1) {
			dane[j + k] = 1;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int C, D, V;
		scanf("%d %d %d", &C, &D, &V);
		for (int i = 0; i <= V; ++i) {
			dane[i] = 0;
		}
		dane[0] = 1;
		for (int i = 0; i < D; ++i) {
			int k;
			scanf("%d", &k);
			add(V, k);
		}
		int result = 0;
		for (int i = 1; i <= V; ++i) {
			if (dane[i] == 0) {
				++result;
				add(V, i);
			}
		}
		printf("Case #%d: %d\n", t, result);

	}
	return 0;
}