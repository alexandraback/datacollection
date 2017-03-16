#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N, S, p;
		scanf("%d%d%d", &N, &S, &p);
		vector<int> t(N);
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &t[i]);
			int smax = 2 + (t[i] - 2) / 3;
			if (t[i] < 2) smax = -1;
			if (t[i] > 29) smax = -1;
			int nmax = (t[i] + 2) / 3;

			if (nmax >= p) {
				ret++;
			} else if (smax >= p && S > 0) {
				S--;
				ret++;
			}
		}
		printf("Case #%d: %d\n", cn, ret);
	}
}
