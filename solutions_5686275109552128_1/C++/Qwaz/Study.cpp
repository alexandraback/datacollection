#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int eat(int count[], int test) {
	int ans = 0, i;
	for (i = 0; i < n; i++) {
		ans += (count[i] - 1)/test;
	}

	return ans + test;
}

int main() {
	freopen("B-large.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		scanf("%d", &n);

		int count[1020], maxCount = 0, i;
		for (i = 0; i < n; i++) {
			scanf("%d", &count[i]);
			maxCount = max(maxCount, count[i]);
		}

		int ans = eat(count, 1);
		for (i = 2; i <= maxCount; i++) {
			ans = min(ans, eat(count, i));
		}

		printf("Case #%d: %d\n", nowCase, ans);
	}

	return 0;
}