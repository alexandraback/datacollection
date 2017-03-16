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
		int N;
		cin >> N;
		vector<double> s(N);
		double X = 0;
		for (int i = 0; i < N; ++ i) {
			cin >> s[i];
			X += s[i];
		}
		vector<double> r(N);
		for (int i = 0; i < N; ++ i) {
			double a = 0, b = 1;
			while (b-a > 1e-8) {
				double c = (a+b) / 2;
				double d = 0;
				for (int j = 0; j < N; ++ j) if (i != j) {
					d += max(0.0, (s[i] - s[j]) / X + c);
				}
				if (d < 1-c) {
					a = c;
				} else {
					b = c;
				}
			}
			r[i] = (a+b) / 2 * 100;
		}
		printf("Case #%d:", tt);
		for (int i = 0; i < N; ++ i) {
			printf(" %f", r[i]);
		}
		puts("");
	}
}
