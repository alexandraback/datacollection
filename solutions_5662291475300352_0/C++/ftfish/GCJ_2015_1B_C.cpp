#include <bits/stdc++.h>
using namespace std;
const int mn = 20;

struct hiker {
	int d, time;
};

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		int n;
		scanf("%d", &n);
		vector<hiker> h;
		for (int i = 0; i < n; ++i) {
			int d, ni, t;
			scanf("%d%d%d", &d, &ni, &t);
			for (int j = 0; j < ni; ++j) {
				h.push_back({d, t + j});
			}
		}
		auto cmp = [](hiker a, hiker b) {return a.d < b.d || (a.d == b.d && a.time < b.time);};
		sort(h.begin(), h.end(), cmp );

		int ans = 0;
		if (h.size() <= 1) {
			ans = 0;
		} else {
			hiker a = h[0];
			hiker b = h[1];
			if (a.time >= b.time) swap(a, b);
			if ((long long)(720 - a.d) * a.time <= (long long)(360 - b.d) * b.time) {
				ans = 1;
			}
		}
		printf("Case #%d: ", Tn);
		printf("%d\n", ans);
	}
	return 0;
}
