
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char argv[]) {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, s, p;
		int res = 0;
		cin >> n >> s >> p;
		vector<int> t(n);
		for (int j = 0; j < n; ++j) {
			int t;
			cin >> t;
			if (t < p) continue;
			if (p - (t - p) / 2 < 2) ++res;
			else if (p - (t - p) / 2 == 2 && s > 0) {++res; --s;}
		}

		cout << "Case #" << i + 1 << ": " << res << endl;
	}
	return 0;
}