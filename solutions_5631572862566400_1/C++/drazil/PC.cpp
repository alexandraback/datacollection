#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

int bff[1100];
int used[1100];

int circle;
map<pair<int, int>, int> group;

void go(int id, int par, int len) {
	if (id == par && len > 0) {
		circle = max(circle, len);
	} else if (id == bff[bff[id]]) {
		int a = id, b = bff[id];
		group[{a, b}] = max(group[{a, b}], len + 1);
		//cout << "g " << a << " " << b << " " << group[{a, b}] << endl;
	} else if (used[id] == 0) {
		used[id] = 1;
		go(bff[id], par, len + 1);
	}
}

int main(void) {
	
	int tc;
	
	cin >> tc;
	
	for(int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> bff[i];
		
		circle = 0;
		group.clear();
		
		for (int i = 1; i <= n; i++) {
			memset(used, 0, sizeof(used));
			go(i, i, 0);
		}
		
		int s = 0;
		for (auto p : group) s += p.second;
		
		cout << "Case #" << t << ": " << max(circle, s) << endl;
	}
	
	return 0;
}

