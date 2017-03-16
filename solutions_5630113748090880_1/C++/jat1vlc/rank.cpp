#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int t, n, x, ca = 1;
	cin >> t;
	while (t--) {
		cin >> n;
		int num = (2*n)-1;
		unordered_map<int, int> um;
		while (num--) {
			for (int i = 0; i < n; i++) {
				cin >> x;
				um[x]++;
			}
		}
		vector<int> v;
		for (auto it = um.begin(); it != um.end(); it++) {
			if (it->second%2 != 0)
				v.push_back(it->first);
		}
		sort(v.begin(), v.end());
		cout << "Case #" << ca++ << ":";
		for (int i : v)
			cout << " " << i;
		cout << endl;
	}
}
