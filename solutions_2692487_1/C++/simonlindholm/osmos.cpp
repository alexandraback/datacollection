#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve() {
	int A, N;
	cin >> A >> N;
	vector<int> motes(N);
	for (int i = 0; i < N; ++i)
		cin >> motes[i];
	sort(motes.begin(), motes.end());

	int neededtoadd = 0, curSize = A;
	int best = N;
	if (A > 1) for (int i = 0; i < N; ++i) {
		// Eat i, skip onwards.
		while (curSize <= motes[i]) {
			curSize += curSize-1;
			++neededtoadd;
		}
		curSize += motes[i];
		best = min(best, neededtoadd + (N - i - 1));
	}

	return best;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}
