#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T;
int N, ans;
int test;
int D1, M1;
int D2, M2;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		if (N == 1) {
			scanf("%d%*d%d", &D1, &M1);
			D2 = D1;
			M2 = M1 + 1;
		} else {
			scanf("%d%*d%d%d%*d%d", &D1, &M1, &D2, &M2);
		}

		ans = 2;

		if (D2 < D1) {
			swap(D1, D2);
			swap(M1, M2);
		}

		double v1 = 360.0 / M1, v2 = 360.0 / M2;

		if (v1 > v2) {
			double time = (double)(D2 - D1) / (v1 - v2);
			if (time * v1 < 360 - D1) {
				double time = (360.0 - D2) / v2;
				if (time * v1 > 360) {
					int tmp = int(time * v1 / 360);
					ans = min(ans, tmp);
				} else ans = min(ans, 0);
			} else ans = min(ans, 0);
		} else {
			double time = (360.0 - D1) / v1;
			if (time * v2 < 360.0 - (D2 - D1)) ans = min(ans, 0);
			else ans = min(ans, 1);
		}


		printf("Case #%d: %d\n", ++test, ans);
	}

	return 0;
}
