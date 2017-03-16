#include <iostream>
using namespace std;

int C, D, V;
int denoms[5];
int newdenoms[5];

int best(int numnew) {
	bool makeable[31];
	makeable[0] = true;
	for (int i = 1; i <= V; i++) makeable[i] = false;

	for (int j = 0; j < D; j++) {
		for (int i = V-denoms[j]; i >= 0; i--) {
			if (makeable[i]) makeable[i+denoms[j]] = true;
		}
	}

	for (int j = 0; j < numnew; j++) {
		for (int i = V-newdenoms[j]; i >= 0; i--) {
			if (makeable[i]) makeable[i+newdenoms[j]] = true;
		}
	}

	bool good = true;
	for (int i = 1; i <= V; i++) good = good && makeable[i];

	if (numnew >= 5 || good) return numnew;

	int ans = 5;
	for (int i = newdenoms[numnew-1]+1; i <= V; i++) {
		newdenoms[numnew] = i;
		int cand = best(numnew+1);
		if (cand < ans) ans = cand;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> C >> D >> V;

		for (int i = 0; i < D; i++) cin >> denoms[i];

		cout << "Case #" << t << ": " << best(0) << '\n';
	}

	return 0;
}
