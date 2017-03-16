#include <bits/stdc++.h>
using namespace std;

int N;

vector< vector<int> > numlist;

vector<int> solve() {
	int x = -1;
	int y = -1;
	vector<bool> hit(2*N-1, 0);
	for (int i = 0; i < N; i++) {
		// find min at i'th loc. see if min occurs only once.
		int m = 1000000;
		for (int j = 0; j < 2*N-1; j++) {
			if (!hit[j]) {
				m = min(numlist[j][i], m);
			}
		}
		int cnt = 0;
		for (int j = 0; j < 2*N-1; j++) {
			if (numlist[j][i] == m) {
				cnt++;
				y = j;
				hit[j] = 1;
			}
		}
		//cout << "m = " << m << endl;
		assert(cnt == 1 || cnt == 2);
		if (cnt == 1) {
			x = i;
			break;
		}
	}
	assert(x != -1);
	assert(y != -1);
	
	// find the one that matches again, tally it's elements
	set<int> removed;
	for (int i = 0; i < N; i++) {
		removed.insert(numlist[y][i]);
		//cout << i << " " << numlist[y][i] << endl;
	}
	
	assert((int)removed.size() == N);
	
	vector<int> ans;
	for (int j = 0; j < 2*N-1; j++) {
		int n = numlist[j][x];
		if (removed.find(n) == removed.end()) {
			ans.push_back(n);
		} else {
			removed.erase(n);
		}
	}
	ans.push_back(numlist[y][x]);
	sort(ans.begin(), ans.end());
	
	//cout << "ans.size = " << ans.size() << endl;
	assert((int)ans.size() == N);
	return ans;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		
		numlist.clear();
		numlist.resize(2*N-1);
		
		for (int i = 0; i < 2*N-1; i++) {
			for (int j = 0; j < N; j++) {
				int a;
				cin >> a;
				numlist[i].push_back(a);
			}
		}
		
		vector<int> res = solve();
		
		cout << "Case #" << icase << ":";
		for (int i = 0; i < N; i++) {
			cout << " " << res[i];
		}
		cout << endl;
	}
	return 0;
}
