#include <bits/stdc++.h>

using namespace std;

struct hiker {
	int starting_degree;
	int time_needed;
	hiker() {}
	hiker(int _sd, int _tn) {
		starting_degree = _sd;
		time_needed = _tn;
	}
	bool operator < (hiker b) const {
		return time_needed < b.time_needed;
	}
	double rt() {
		return double(360-starting_degree)*double(time_needed)/double(360);
	}
	double superrt() {
		return rt() + double(time_needed);
	}
};

int n;
hiker H[20];

int solve() {
	n = 0;
	int k; scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int d, h, m; scanf("%d%d%d", &d, &h, &m);
		for (int _h = 0; _h < h; _h++) {
			H[++n] = hiker(d, m+_h);
		}
	}
	
	sort(H+1, H+n+1);
	
	int ret = 0;
	
	for (int i = 1; i <= n; i++) {
		bool su = false;
		for (int j = 1; j <= n; j++) {
			if (H[j].superrt() < H[i].rt()) su = true;
		}
		ret += su;
	}
	return ret;
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}