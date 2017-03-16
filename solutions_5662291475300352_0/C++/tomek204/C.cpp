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

int dist() {
	return H[1].starting_degree - H[2].starting_degree + 360;
}

double kiedy_wyprzedzi() {
	return double(-dist())/(double(360)*(double(1)/double(H[1].time_needed)-double(1)/double(H[2].time_needed)));
}

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
	
	//printf("%lf %lf\n", kiedy_wyprzedzi(), H[1].rt());
	
	if (H[1].time_needed == H[2].time_needed) return 0;
	return H[1].superrt() <= H[2].rt();
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}