#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[2 * 1001001];
int main() {
	int T, N;
	int a[30];
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		bool found = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < 2 * 1001001; i++) v[i].clear();
		printf("Case #%d:\n", t + 1);
		for (int i = 0; i < (1 << N); i++) {
			int s = 0;
			for (int j = 0; j < N; j++) {
				if (i & 1 << j) s += a[j];
			}
			if (v[s].size()) {
				for (int k = 0; k < v[s].size(); k++) {
					printf("%d ", v[s][k]);
				}
				printf("\n");
				for (int j = 0; j < 20; j++) {
					if (i & 1 << j) printf("%d ", a[j]);
				}
				printf("\n");
				found = 1;
				break;
			}
			for (int j = 0; j < N; j++)
				if (i & 1 << j) v[s].push_back(a[j]);
		}
		if (!found) printf("Impossible\n");
	}
	return 0;
}
