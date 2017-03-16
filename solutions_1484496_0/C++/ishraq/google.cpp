#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 20

using namespace std;

int vals[MAX_N];
int backtrack[3000000];
int n;

int main() {
	int T;
	scanf("%d", &T);
	for (int rayge = 1; rayge <= T; rayge++) {
		printf("Case #%d:\n", rayge);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
		for (int mask = 1; mask < (1 << 20); mask++) {
			vector<int> set1, set2;
			vector<int> set2_sums;
			int subset_sum = 0;
			for (int i = 0; i < 20; i++) {
				if (mask & (1 << i)) {
					set1.push_back(vals[i]);
					subset_sum += vals[i];
				} else {
					set2.push_back(vals[i]);
				}
			}
			backtrack[subset_sum] = -1;

			for (int i = 0; i < set2.size(); i++) {
				int tmp = set2_sums.size();
				for (int j = 0; j < tmp; j++) {
					set2_sums.push_back(set2[i] + set2_sums[j]);
					backtrack[set2[i] + set2_sums[j]] = set2_sums[j];
				}
				set2_sums.push_back(set2[i]);
				backtrack[set2[i]] = 0;
			}
			if (backtrack[subset_sum] != -1) {
				for (int i = 0; i < set1.size(); i++) {
					printf("%d ", set1[i]);
				}
				printf("\n");
				int curr = subset_sum;
				while (curr != 0) {
					printf("%d ", curr - backtrack[curr]);
					if (curr == backtrack[curr]) break;
					curr = backtrack[curr];
				}
				printf("\n");
				goto next;
			}
		}
		printf("Impossible\n");
		next:;
	}
}
