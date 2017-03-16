#include <cstdio>

using std::scanf;
using std::printf;

static double testcase(double C, double F, double X) {
	double s = 2;
	double t = 0;
	double tx = t + X / s;
	for(;;) {
		t += C / s;
		s += F;
		double tx1 = t + X / s;
		if(tx1 >= tx)
			return tx;
		tx = tx1;
	}
}

static double testcase() {
	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);
	return testcase(C, F, X);
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		printf("Case #%d: %.7f\n", t, testcase());
}
