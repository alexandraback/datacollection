#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

#define INF 200000000

using namespace std;

long solve(int ms, int pos, vector<int> &motes, long actions, map<string, long> &mem) {
	stringstream ss; ss << ms << " " << pos << " " << actions;
	string memo = ss.str();
	if (mem.find(memo) != mem.end()) return mem[memo];
	long sol = INF;
	if (pos >= motes.size()) return actions;
	if (ms > motes[pos]) 
		sol = solve(ms + motes[pos], pos + 1, motes, actions, mem);
	else {
		if (ms > 1)
			sol = solve(ms * 2 - 1, pos, motes, actions + 1, mem);
		sol = min(sol, solve(ms, pos + 1, motes, actions + 1, mem));
	}

	mem[memo] = sol;
	return sol;
}

int main() {
	int tc; cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int ms; cin >> ms;
		int nm; cin >> nm;
		vector<int> motes;
		map<string, long> mem;
		for (int m = 0; m < nm; m++) {
			int mote; cin >> mote;
			motes.push_back(mote);
		}
		sort (motes.begin(), motes.end());
		cout << "Case #" << i << ": " << solve (ms, 0, motes, 0, mem) << endl;
	}
		


}
