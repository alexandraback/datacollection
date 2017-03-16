#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const int INF = 0x3f3f3f3f;

int x[MAXN];

int main() {
	int tc, cn = 0;
	int A, n;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &A, &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		sort(x, x+n);
		int cc = 0, mn = INF;
		if (A == 1) {
			mn = n;
		} else {
			for (int i=0; i<n; ++i) {
				mn = min(cc+n-i, mn);
				if (A > x[i]) {
					A += x[i];
				} else {
					while (A <= x[i]) {
						A += A - 1;
						++cc;
					}
					A += x[i];
					mn = min(cc+n-i-1, mn);
				}
			}
			mn = min(mn, cc);
			if (mn == INF) mn = 0;
		}
		printf("Case #%d: %d\n", ++cn, mn);
	}

	return 0;
}
