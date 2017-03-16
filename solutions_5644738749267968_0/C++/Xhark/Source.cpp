#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
double A[1024], B[1024];
int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &A[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", &B[i]);
		}
		sort(A, A + n);
		sort(B, B + n);
		int sola = 0, solb = n;

		int e = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (A[i] < B[e]) {
				solb--;
				e--;
			}
		}

		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; i+j < n; j++) {
				if (A[i + j] < B[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				sola = n - i;
				break;
			}
		}

		static int cs = 1;
		printf("Case #%d: %d %d\n", cs++, sola, solb);
	}
	return 0;
}