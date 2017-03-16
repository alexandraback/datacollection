#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case){
		double C, F, X;
		cin >> C >> F >> X;
		double x = 2;

		double ans = X / x;
		double t = 0;
		while (1){
			t += C / x;
			x += F;
			if (ans < t + X / x) break;
			ans = t + X / x;
		}

		printf("Case #%d: %.7f\n", Case, ans);
	}

	return 0;
}