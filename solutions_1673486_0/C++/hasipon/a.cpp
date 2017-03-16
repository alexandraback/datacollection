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
		double r = B+2;
		for (int bs = 0; bs <= A; ++ bs) {
			double e = 0;
			for (int k = 0; k < (1<<A); ++ k) {
				double prob = 1;
				bool err = false;
				for (int i = 0; i < A; ++ i) {
					if ((k>>i)&1) {
						prob *= p[i];
					} else {
						prob *= 1 - p[i];
						if (i < A-bs) err = true;
					}
				}
				if (err) {
					e += prob * (bs + bs + B-A + 1 + B + 1);
				} else {
					e += prob * (bs + bs + B-A + 1);
				}
			}
			r = min(r, e);
		}
		printf("Case #%d: %f\n", tt, r);
	}
}
