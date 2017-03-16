#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
#include <stdint.h>
#include <utility>
#include <set>
#include <stack>
#define DEBUG 0
#define LOG if(DEBUG)
using namespace std;
typedef int64_t intt;
typedef long double ld;
#define MAX_VAL	LLONG_MAX 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((y) > (x) ? (x) : (y))
template <typename T>
void printvec(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}

struct hiker {
	int m, d;
	hiker(int a, int b) : m(a), d(b) {}
	hiker() : m(0), d(0) {}

	bool operator<(hiker h) const {
		if(d != h.d) {
			return d < h.d;
		}
		return m > h.m;
	}
};

ld eps = 1e-9;

int recursive(vector<hiker> H, int f, ld t) {
	ld pos = fmod(360 * t / H[f].m + H[f].d, 360);
	int nevent = -1;
	ld ntime = (360 - pos) / 360 * H[f].m;
	for(int i = 0; i < H.size(); i++) {
		if(i == f) continue;
		ld opos = fmod(360 * t / H[i].m + H[i].d, 360);
		if(opos > pos) opos -= 360;
		ld time = (pos - opos) / (((ld)360)/H[i].m - ((ld)360)/H[f].m);
		if(time > 0 && time < ntime) {
			ntime = time;
			nevent = i;
		}
	}

	if(nevent == -1) {
		return 0;
	} else {
		int m = 1 + recursive(H, f, t + ntime + eps);
		vector<pair<ld, int> > positions;
		for(int i = 0; i < H.size(); i++) {
			if(i == f) continue;
			positions.push_back(make_pair<ld, int>(fmod(360 * (t + ntime) / H[f].m + H[f].d, 360), i));
		}
		sort(positions.begin(), positions.end());

		int nf = upper_bound(positions.begin(), positions.end(), make_pair(pos, f))->second;

		m = min(m, 1 + recursive(H, nf, t + ntime + eps));

		return m;
	}
}

void code0() {
	int N;
	cin >> N;

	vector<hiker> h;
	int idx = 0;
	for(int i = 0; i < N; i++) {
		int d, n, m;
		cin >> d >> n >> m;
		for(int j = 0; j < n; j++) {
			h.push_back(hiker(m + j, d));
		}
	}
	sort(h.begin(), h.end());

	if(h.size() < 2) {
		cout << 0 << endl;
		return;
	}

	ld p0 = h[0].d;
	ld p1 = h[1].d;
	int m0 = h[0].m;
	int m1 = h[1].m;
	if(h[0].m < h[1].m) {
		ld it = h[1].d - h[0].d / (((ld)360)/h[0].m - ((ld)360)/h[1].m);
		p1 = fmod(360 * (it + eps) / h[0].m + h[0].d, 360);
		p0 = fmod(360 * (it + eps) / h[1].m + h[1].d, 360);
		m0 = h[1].m;
		m1 = h[0].m;
	}

	ld tleft = (360 - p0) / 360 * m0;
	ld tint = (p0 - (p1 - 360)) / (((ld)360)/m1 - ((ld)360)/m0);
	if(tleft < tint) {
		cout << 0 << endl;
		return;
	} else {
		cout << 1 << endl;
		return;
	}
}

void code1() {
	int N;
	cin >> N;
	vector<hiker> h;
	int idx = 0;
	for(int i = 0; i < N; i++) {
		int d, n, m;
		cin >> d >> n >> m;
		for(int j = 0; j < n; j++) {
			h.push_back(hiker(m + j, d));
		}
	}
	sort(h.begin(), h.end());

	cout << recursive(h, 0, eps) << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code0();
	}
}

