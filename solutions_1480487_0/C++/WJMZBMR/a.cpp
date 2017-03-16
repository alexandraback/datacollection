#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 200 + 10;

void work() {
	int n;
	double s[MAX_N];
	cin >> n;
	double x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		x += s[i];
	}

	for (int i = 0; i < n; ++i) {
		double l = 0, r = 1;
		while (l + 1e-10 < r) {
			double m = (l + r) / 2;
			double rem = 1 - m;
			double me = s[i] + m * x;

			for (int j = 0; j < n; ++j)
				if (i != j) {
					if (s[j] < me) {
						rem -= (me - s[j]) / x;
					}
				}
			if (rem < 0)
				r = m;
			else
				l = m;
		}
		printf("%0.10lf ", r * 100);
	}
	puts("");
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
