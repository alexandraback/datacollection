#include <iostream>
#include <map>

using namespace std;

map<int, int> wow;

int main() {
	int t; cin >> t;
	for (int test = 1; test <= t; ++test) {
		int n; cin >> n;
		wow.clear();
		for (int i = 0; i < 2*n-1; ++i) {
			for (int j = 0; j < n; ++j) {
				int curr; cin >> curr; wow[curr]++;
			}
		}
		cout << "Case #" << test << ":";
		for (map<int, int>::iterator it = wow.begin(); it != wow.end(); ++it) {
			if (it->second % 2 == 1) cout << " " << it->first;
		}
		cout << endl;
	}
	return 0;
}