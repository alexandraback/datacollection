#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int A, B;
		cin >> A >> B;
		vector<double> p(A);
		for (int i = 0; i < A; ++ i) {
			cin >> p[i];
		}
		vector<double> errprob(A+1);
		errprob[0] = 0;
		double pp = 1;
		for (int i = 0; i < A; ++ i) {
			errprob[i+1] = errprob[i] + pp * (1-p[i]);
			pp *= p[i];
		}
		double r = B+2;
		for (int bs = 0; bs <= A; ++ bs) {
			double e = errprob[A-bs] * (bs + bs + B-A + 1 + B + 1) + (1-errprob[A-bs]) * (bs + bs + B-A + 1);
			r = min(r, e);
		}
		printf("Case #%d: %f\n", tt, r);
	}
}
