
#include <iostream>

#include <algorithm>

#include <map>
#include <vector>

using namespace std;

const int MAX = 11;

struct combo {
	int j;
	int p;
	int s;

	combo(int _j, int _p, int _s) {
		j = _j;
		p = _p;
		s = _s;
	}
};


inline int index(int a, int b) {
	return a * MAX + b;
}


inline int bitc(unsigned int u) {
	unsigned int uCount;
	uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
	return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

bool check(const vector<combo> &v, int K) {
	static int worn_jp[MAX*MAX];
	static int worn_js[MAX*MAX];
	static int worn_ps[MAX*MAX];

	for (int i = 0; i < MAX*MAX; i++) {
		worn_jp[i] = worn_js[i] = worn_ps[i] = 0;
	}

	for (combo c : v) {
		int jp = index(c.j, c.p);
		int js = index(c.j, c.s);
		int ps = index(c.p, c.s);
		if (worn_jp[jp] < K && worn_js[js] < K && worn_ps[ps] < K) {
			worn_jp[jp]++;
			worn_js[js]++;
			worn_ps[ps]++;
		} else {
			return false;
		}
	}
	return true;
}

void solve() {
	int J, P, S, K;

	cin >> J >> P >> S >> K;

	int worn_jp[MAX*MAX];
	int worn_js[MAX*MAX];
	int worn_ps[MAX*MAX];

	vector<combo> res;
	vector<combo> all;

	for (int i = 0; i < MAX*MAX; i++) {
		worn_jp[i] = worn_js[i] = worn_ps[i] = 0;
	}

	for (int j = 1; j <= J; j++) {
		for (int p = 1; p <= P; p++) {
			for (int s = 1; s <= S; s++) {
				combo c = {j, p, s};
				int jp = index(j, p);
				int js = index(j, s);
				int ps = index(p, s);
				if (worn_jp[jp] < K && worn_js[js] < K && worn_ps[ps] < K) {
					worn_jp[jp]++;
					worn_js[js]++;
					worn_ps[ps]++;
					res.push_back(c);
				}
				all.push_back(c);
			}
		}
	}

	int max = res.size();
	unsigned int BMAX = J * P * S;
	unsigned int BMV = 1 << BMAX;
	for (unsigned int c = 0; c < BMV; c++) {
		if (bitc(c) > max) {
			vector<combo> alt;
			for (int i = 0; i < BMAX; i++) {
				if ((1 << i) & c) {
					alt.push_back(all[i]);
				}
			}
			if (check(alt, K)) {
				//cout << endl << "---- ALTERNATIVE FOUND ----" << endl;
				max = alt.size();
				res = alt;
			}
		}
	}

	cout << res.size() << endl;
	for (combo c : res) {
		cout << c.j << ' ' << c.p << ' ' << c.s << endl;
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

