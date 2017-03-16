#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_HEIGHT = 2500;

int cnt[MAX_HEIGHT + 7];
int n;

int main() {
	int tests;
	scanf("%d", &tests);
	for (int testCount = 1; testCount <= tests; testCount++) {
		scanf("%d", &n);
		fill(cnt, cnt + MAX_HEIGHT + 1, 0);
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				cnt[x] ^= 1;
			}
		}
		vector<int> answer;
		for (int i = 1; i <= MAX_HEIGHT; i++) {
			if (cnt[i]) {
				answer.push_back(i);
			}
		}
		printf("Case #%d:", testCount);
		for (int i = 0; i < n; i++) {
			printf(" %d", answer[i]);
		}
		puts("");
	}
	return 0;
}
