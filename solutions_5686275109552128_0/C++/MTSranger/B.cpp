#include <iostream>
#include <algorithm>

using namespace std;

int thresh[1001];
int maxstack;

bool possible(int t) {
	for (int i = 0; i < t; i++) {
		int moves = 0;
		for (int j = t-i+1; j <= maxstack; j += t-i) {
			moves += thresh[j];
		}
		if (moves <= i) return true;
	}
	return false;
}

int main() {
	int nc; cin >> nc;
	for (int cs = 1; cs <= nc; cs++) {
		int nd; cin >> nd;
		int diners[nd];
		for (int i = 0; i < nd; i++) {
			cin >> diners[i];
		}
		sort(diners, diners+nd);

		maxstack = diners[nd-1];
		int cnt = nd;
		int ii = 0;
		for (int t = 0; t <= maxstack; t++) {
			while (diners[ii] < t) {
				cnt--; ii++;
			}
			thresh[t] = cnt;
		}

		int lo = 0;
		int hi = maxstack;
		while (hi - lo > 2) {
			int mid = (lo + hi)/2;
			if (possible(mid)) hi = mid;
			else lo = mid;
		}
		while (lo < hi && !possible(lo)) lo++;

		cout << "Case #" << cs << ": " << lo << endl;
	}
}
