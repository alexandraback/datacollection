#include <iostream>
#include <vector>
#include <algorithm>

#define INF 200000000

using namespace std;

long solve(int ms, int pos, vector<int> &motes, long actions) {
	//cout << "Solve: " << pos << " " << ms << endl;
	long sol = INF;
	if (pos >= motes.size()) return actions;
	if (ms > motes[pos]) 
		sol = solve(ms + motes[pos], pos + 1, motes, actions);
	else if (ms > 1)
		sol = solve(ms * 2 - 1, pos, motes, actions + 1);
	sol = min(sol, solve(ms, pos + 1, motes, actions + 1));

	return sol;
}

int main() {
	int tc; cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int ms; cin >> ms;
		int nm; cin >> nm;
		vector<int> motes;
		for (int m = 0; m < nm; m++) {
			int mote; cin >> mote;
			motes.push_back(mote);
		}
		sort (motes.begin(), motes.end());
		cout << "Case #" << i << ": " << solve (ms, 0, motes, 0) << endl;
	}
		


}
