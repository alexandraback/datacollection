#include <iostream>

using namespace std;

int main() {
	int nTests;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; ++test) {
		int A, B;
		scanf("%d %d", &A, &B);
		double p[A];
		double pb = 1;
		for (int i = 0; i < A; ++i) {
			scanf("%lf", &p[i]);
			pb *= p[i];
		}
		double ans = 1 + B + 1; // give up
		for (int lastKept = A - 1; lastKept >= 0; --lastKept) {
			double E = ((A - lastKept - 1) + (B - 1 - lastKept) + 1) + (1 - pb) * (B + 1);
			ans = min(E, ans);
			pb /= p[lastKept];
		}
		printf("Case #%d: %.6lf\n", test, ans);
	}
	return 0;
}
