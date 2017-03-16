#include <iostream>
#include <cassert>
using namespace std;

int D;

int P[1001];
int applied[1001];
int cur[1001];

int apply(int p, int n) {
	// ceiling{p / (n+1)}
	return (p + n) / (n + 1);
}

int currentMaxIndex() {
	int j = 0;
	int mx = cur[0];
	for (int i = 1; i < D; i++) {
		if (cur[i] > mx) {
			j = i;
			mx = cur[i];
		}
	}
	return j;
}

int solve() {
	for (int i = 0; i < D; i++) {
		applied[i] = 0;
		cur[i] = apply(P[i], applied[i]);
		assert(cur[i] == P[i]);
	}
	int j = currentMaxIndex();
	// best if zero special moves
	int res = cur[j];
	for (int moves = 1; moves <= res; moves++) {
		applied[j]++;
		cur[j] = apply(P[j], applied[j]);
		j = currentMaxIndex();
		res = min(res, moves + cur[j]);
	}
	return res;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> D;
		for (int i = 0; i < D; i++) {
			cin >> P[i];
		}
		int res = solve();
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}

