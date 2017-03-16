#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int t, n, ans;
const int l = 50;
struct Hiker {
	int d, h, m;
	Hiker(){};
	Hiker(int a, int b, int c): d(a), h(b), m(c){};
};
vector<Hiker> v;
map<int, bool> m;

int main() {
	cin >> t;
	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		cin >> n;
		v.clear();
		m.clear();
		for (int i = 0; i < n; i++) {
			Hiker h;
			cin >> h.d >> h.h >> h.m;

			if (h.h == 1) {
				v.push_back(h);
				m[h.m] = 1;
			}
			else {
				// cout << h.h << endl;
				for (int k = 0; k < h.h; k++) {
					Hiker h2(h.d,1,h.m+k);
					v.push_back(h2);
					m[h.m+k] = 1;
				}
			}
		}

		if (v.size() <= 1 || m.size() <= 1) {
			printf("0\n");
		}
		else {
			// for (int i = 0; i < v.size(); i++) {
			// 	printf("%d %d %d\n", v[i].d, v[i].h, v[i].m);
			// }

			// more than one hiker and more than one speed
			int idx = 0, idx2 = 1;
			if (v[0].m < v[1].m) {
				idx = 1;
				idx2 = 0;
			}
			// printf("%.0f\n", (double)(v[idx].m + 0.0));

			ans = 0;
			double tt = (360.0 - v[idx].d) / v[idx].m;
			double tt2 = (360.0 - v[idx2].d) / v[idx2].m;
			double e = v[idx2].d + tt * v[idx2].m;
			double e2 = v[idx].d + tt2 * v[idx].m;
			// printf("%.5f %.5f\n", e, e2);
			if (e < 360.0) {	// one hiker at starting point, another hiker still in circle
				// same pos with second hiker, prevent another hiker move over herbert
				if (e2 < 720.0) {
					ans = 0;
				}
				else {
					ans = 1;
				}
			}

			// printf("%.5f\n", tt);
			printf("%d\n", min(ans, 1));
		}
	}
	return 0;
}
