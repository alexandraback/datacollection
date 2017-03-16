#include <bits/stdc++.h>
using namespace std;

typedef double DB;
const int N = 4;
const DB EPS = 1e-10;
inline DB getSign(const DB &a) { return (a > EPS) - (a < -EPS); }

int run() {
	int _;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		DB C, F, X, P = 2.0;
		cin >> C >> F >> X;
		DB currentTime = 0, bestTime = DBL_MAX;
		while (1) {
			if (getSign(currentTime + X / P - bestTime) > 0) break;
			bestTime = currentTime + X / P;
			currentTime += C / P;
			P += F;
		}
		cout << "Case #" << cas << ": " << bestTime << endl;
	}
	return 0;
}

int main() {
	//freopen("in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout << setiosflags(ios::fixed) << setprecision(10);
	return run();
}
