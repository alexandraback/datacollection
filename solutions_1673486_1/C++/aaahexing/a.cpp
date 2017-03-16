#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cas, A, B;
double ans, tmp, p[100010], s[100010];

int main() {
	cin >> cas;
	for (int ca = 1; ca <= cas; ++ca) {
		cin >> A >> B;
		s[0] = 1.0;
		for (int i = 1; i <= A; ++i) {
			cin >> p[i];
			s[i] = s[i - 1] * p[i];
		}
		ans = 1 + B + 1;
		int rem = B - A;
		tmp = (rem + 1) + (1.0 - s[A]) * (B + 1);
		//printf("%d, %d, tmp = %lf\n", rem + 1, B, tmp);
		ans = min(ans, tmp);
		for (int c = 1; c <= A; ++c) {
			tmp = (c + rem + c + 1) + (1.0 - s[A - c]) * (B + 1);
			//printf("%d, %d, tmp = %lf\n", c + rem + c + 1, B, tmp);
			ans = min(ans, tmp);
		}
		printf("Case #%d: %.6lf\n", ca, ans);
	}
	return 0;
}
