#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		map<int, vector<int>> m;
		for (int i = 0, ilen = (1 << 20); i < ilen; ++i) {
			int sum = 0;
			for (int j = 0; j < 20; ++j) {
				if (i & (1 << j)) {
					sum += a[j];
				}
			}
			m[sum].push_back(i);
			if (m[sum].size() > 1) {
				break;
			}
		}
		bool ok = false;
		for (map<int, vector<int>>::const_iterator i = m.begin(), iend = m.end(); i != iend; ++i) {
			if (i->second.size() > 1) {
				cout << "Case #" << test << ": " << endl;
				for (int j = 0; j < 20; ++j) if (i->second[0] & (1 << j)) {
					cout << a[j] << " ";
				}
				cout << endl;
				for (int j = 0; j < 20; ++j) if (i->second[1] & (1 << j)) {
					cout << a[j] << " ";
				}
				cout << endl;
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "Case #" << test << ": Impossible";
		}
	}
}
