#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int test_cases;
	cin >> test_cases;
	for (int tc = 1; tc <= test_cases; ++tc) {
		int n;
		cin >> n;
		map<int, int> cnt; 
		for (int i = 1; i != 2 * n; ++i) {
			int x;
			for (int j = 0; j != n; ++j) {
				cin >> x;
				cnt[x] += 1;
			}
		}
		vector<int> ans;
		for (pair<int, int> p : cnt) {
			if (p.second % 2) {
				ans.push_back(p.first);
			}
		}
		cout << "Case #" << tc << ":";
		for (int x : ans) {
			cout << " " << x;
		}
		cout << endl;
	}
	return 0;
}
