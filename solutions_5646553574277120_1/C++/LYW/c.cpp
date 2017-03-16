#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int C, D, V;
		scanf("%d %d %d", &C, &D, &V);

		int ans = 0;
		long long sum = 0;
		for (int i = 0; i < D; i++) {
			int temp;
			scanf("%d", &temp);

			while (sum < V && sum + 1 < temp) {
				sum += C * (sum + 1);
				ans ++;
			}
			sum += (long long)temp * C;
		}

		while (sum < V) {
			sum += C * (sum + 1);
			ans ++;
		}

		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}
