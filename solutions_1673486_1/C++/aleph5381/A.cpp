#include <cstdio>
#include <cstring>
using namespace std;

double p[100000];
double P[100000];

int main(void)
{
	int T_;
	scanf("%d ", &T_);
	for (int i_ = 1; i_ <= T_; ++i_) {
		printf("Case #%d: ", i_);
		int A, B;
		scanf("%d %d", &A, &B);
		for (int i=0; i<A; ++i) {
			scanf("%lf", p+i);
		}
		P[0] = p[0];
		for (int i=1; i<A; ++i) {
			P[i] = P[i-1] * p[i];
		}
		// 1. keep typeping
		double ans = P[A-1] * (B - A + 1) + (1 - P[A-1]) * (B - A + 1 + B + 1);
		//double ans = (2*B - A + 2) - P[A-1] * (B + 1);
		// 2. backsapce
		for (int j=1; j<A; ++j) {
			double t = P[A-j-1] * (B - A + 1 + 2*j)
				+ (1 - P[A-j-1]) * (B - A + 1 + 2*j + B + 1);
			if (t < ans)
				ans = t;
		}
		// 3. giveup
		double ans3 = B + 2;
		if (ans3 < ans)
			ans = ans3;
		printf("%f\n", ans);
	}
	return 0;
}
