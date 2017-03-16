#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	
	for (int ti = 1; ti <= T; ti++) {
		int A, B;
		cin >> A >> B;
		static double p[100000];
		for (int i = 0; i < A; i++) cin >> p[i];
		double ans = B * B;
		
		for (int k = 0; k <= A; k++) {
			double x = 1.0;
			for (int i = 0; i < A - k; i++) x *= p[i];
			double r = x * (1 + B - A + k) + (1 - x) * (1 + B - A + B + k + 1) + k;
			ans = min(ans, r);
		}
		ans = min(ans, (double) 2 + B);		
		printf("Case #%d: %f\n", ti, ans);
	}
	
	return 0;
}
