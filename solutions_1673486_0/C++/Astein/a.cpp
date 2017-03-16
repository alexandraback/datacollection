#include <cstdio>
#include <vector>

using namespace std;

double pp[100001];

int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		double ret;
		int A, B;
		scanf("%d%d", &A, &B);
		vector<double> p(A);
		for (int i = 0; i < A; ++i)
			scanf("%lf", &p[i]);
		ret = B + 2;
		double maxp = 1.0;
		for (int i = 0; i < A; ++i) {
			pp[i] = maxp * (1.0 - p[i]);
			maxp *= p[i];
		}
		pp[A] = maxp;

		double ppp = 0.0;
		for (int bs = A; bs >= 0; --bs) {
			int numc = B - A + 1 + 2 * (A - bs);
			int numi = 2 * (B + 1) - A + 2 * (A - bs);
			ppp += pp[bs];
			double t = numc * ppp + numi * (1.0 - ppp);
			if (t < ret) ret = t;
		}
		printf("Case #%d: %.8lf\n", cn, ret);
	}
}
