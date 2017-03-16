#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int type[22], keys[210], n;
vector<int> keysInside[22];


vector<int> sol;

bool mem[1<<21];

bool bt(int state) {
	if (mem[state]) return false;
	mem[state] = true;
	if (state == (1<<n) - 1) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		if (state & (1 << i)) continue;
		if (keys[type[i]] > 0) {
			keys[type[i]]--;
			for(int j = 0; j < keysInside[i].size(); j++) keys[keysInside[i][j]] ++;
			if (bt(state|(1<<i))) {
				sol.push_back(i);
				return true;
			}
			for(int j = 0; j < keysInside[i].size(); j++) keys[keysInside[i][j]] --;
			keys[type[i]]++;
		}
	}
	return false;
}

int main () {
	int t;
	cin >> t;
	for (int caso = 1; caso <= t; caso++) {
		int k;
		cin >> k >> n;
		memset(keys, 0, sizeof(keys));
		memset(mem,0,sizeof(mem));
		for (int i = 0; i < k; i++) {
			int key;
			cin >> key;
			keys[key]++;
		}
		for (int i = 0; i < n; i++) {
			int ki;
			cin >> type[i] >> ki;
			keysInside[i] = vector<int>(ki,0);
			for (int j = 0; j < ki; j++) {
				cin >> keysInside[i][j];
			}
		}
		sol.clear();
		if (bt(0)) {
			cout << "Case #" << caso << ": ";
			for (int i = sol.size()-1; i >= 0; i--) {
				if (i<sol.size()-1) cout << " "; cout << sol[i]+1;
			}
			cout << endl;
		} else {
			cout << "Case #" << caso << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}

