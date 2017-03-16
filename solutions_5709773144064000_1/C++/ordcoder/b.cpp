#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#if !defined(ID)
#define ID(x)
#endif
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){ID(cerr<<' '<<_;E($...);)}
#define E($...) E(#$,'=',$,'\n')

typedef long double flt;

int main() {
	ios_base::sync_with_stdio(false);
	int tn;
	scanf("%d", &tn);
	for (int tc = 1; tc <= tn; ++tc) {
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		flt ans = x / 2;
		flt t = 0;
		for (int i = 1; t < ans; ++i) {
			t += flt(c) / flt(2.0 + (i - 1) * f);
			ans = min(ans, t + x / flt(2.0 + i * f));
		}
		printf("Case #%d: %.7lf\n", tc, double(ans));
	}
	return 0;
}
