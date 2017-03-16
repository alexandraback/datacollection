#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	int testNum;
	scanf("%d", &testNum);
	for (int test = 1; test <= testNum; ++test) {
		int N;
		int a[1005];
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		sort(a, a + N);
		reverse(a, a + N);
		int ans = 1 << 30;
		for (int i = a[0]; i >= 1; --i) {
			int now = 0;
			for (int j = 0; j < N; ++j) {
				if (a[j] <= i) break;
				now += (a[j] - 1) / i;
			}
			now += i;
			ans = min(ans, now);
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}