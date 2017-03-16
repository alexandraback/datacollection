#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int A, N;
		scanf("%d%d", &A, &N);
		vector<int> a(N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);

		int ret = N; // remove all
		sort(a.begin(), a.end());
		
		int start = 0;
		for (int i = 0; i < 20; ++i) {
			for (int j = start; j < N; ++j) {
				if (A > a[j]) {
					start++;
					A += a[j];
				}
				else {
					break;
				}
			}
//			printf("A : %d, start : %d, remain : %d\n", A, start, N - start);
			if (N - start + i < ret) ret = N - start + i;
			if (A > 1000000) break;
			A += (A - 1);
		}
		printf("Case #%d: %d\n", cn, ret);
	}
}
