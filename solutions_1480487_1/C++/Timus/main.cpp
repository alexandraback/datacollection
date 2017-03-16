#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
		int n;
		cin >> n;
		vector<int> a;
		a.resize(n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
			cin >> a[i], sum += a[i];
		printf("Case #%d: ", testnum);
		for (int i = 0; i < n; ++i) {
			double L = 0, R = 1;
			for (int it = 0; it < 80; ++it) {
				double m = (L + R) / 2;
				double tek = a[i] + sum * m;
				double ost = 1 - m;
				double mx = -1;
				for (int j = 0; j < n; ++j)
					if (i != j) {
						if (a[j] > tek)
							continue;
						ost -= (tek - a[j]) * 1.0 / sum;
					}
				if (ost >= 0)
					L = m;
				else R = m;
			}
			printf("%.7f ", L * 100);
		}
		printf("\n");
	}
}
