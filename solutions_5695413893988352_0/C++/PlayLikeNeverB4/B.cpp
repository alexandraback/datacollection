#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int N;
string A, B, C;
int ansA, ansB, ansDiff;

void go(int pos, int a, int b) {
	if (pos == 2 * N) {
		int diff = abs(a - b);
		if (diff < ansDiff ||
		   (diff == ansDiff && a < ansA) ||
		   (diff == ansDiff && a == ansA && b < ansB)) {
			ansDiff = diff;
			ansA = a;
			ansB = b;
		}
		return;
	}

	if (isdigit(C[pos])) {
		int d = C[pos] - '0';
		if (pos < N) {
			go(pos + 1, a * 10 + d, b);
		} else {
			go(pos + 1, a, b * 10 + d);
		}
	} else {
		for (int d = 0; d < 10; d++) {
			if (pos < N) {
				go(pos + 1, a * 10 + d, b);
			} else {
				go(pos + 1, a, b * 10 + d);
			}
		}
	}
}

void solve() {
	N = (int) A.size();
	C = A + B;
	ansDiff = INF;
	go(0, 0, 0);
}

string transf(int x) {
	stringstream ss;
	ss << x;
	string ret;
	ss >> ret;
	while ((int) ret.size() < N) {
		ret = string("0") + ret;
	}
	return ret;
}

int main() {
	assert(freopen("B.in", "r", stdin));
	assert(freopen("B.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >> A >> B;
		solve();
		cout << transf(ansA) << ' ' << transf(ansB) << endl;
		
		cerr << t << endl;
	}

	return 0;
}
