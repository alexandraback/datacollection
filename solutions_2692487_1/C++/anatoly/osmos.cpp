#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solve(vector<int>& moles, int c, int a) {
	if (c >= moles.size())
		return 0;

	if (a > moles[c]) {
		return solve(moles, c+1, a + moles[c]);
	} else if (a > 1) {
		int newa = a + a - 1;
		if (newa > moles[c])
			return 1 + solve(moles, c, newa);
		
		int steps = 1;
		while (newa <= moles[c]) {
			newa = newa + newa - 1;
			++steps;
		}

		int x1 = steps + solve(moles, c + 1, newa + moles[c]); // add 
		int x2 = 1 + solve(moles, c + 1, a); // remove
		return min(x1, x2);
	} else {
		// a == 1
		return 1 + solve(moles, c + 1, a);
	}
}

int main()
{
	int T; cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		int A, N; cin >> A >> N;

		vector<int> moles(N);
		for (int i = 0; i < N; ++i) {
			cin >> moles[i];
		}

		sort(moles.begin(), moles.end());

		cout << "Case #"  << tc+1 << ": " << solve(moles, 0, A) << endl;
	}

	return 0;
}

