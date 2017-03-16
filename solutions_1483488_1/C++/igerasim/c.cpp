#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int cnt(int A, int x, int B)
{
	int res = 0;
	int dd = 1;
	while (dd * 10 < x) dd *= 10;
	for (int g = 1, d = 10; dd >= 10; ++g, d *= 10, dd /= 10) {
		int y = (x % d) * dd + x / d;
		if (y > x && y <= B) {
			res++;
//			cerr << A << " <= " << x << " < " << y << " <= " << B << endl;
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;
	vector<vector<int> > v;
	v.resize(2000001);
	for (int x = 1; x <= 2000000; x++) {
		if (x % 10000 == 0) {
			cerr << "> " << x << endl;
		}
		vector<int>& u = v[x];
		int dd = 1;
		while (dd * 10 < x) dd *= 10;
		for (int g = 1, d = 10; dd >= 10; ++g, d *= 10, dd /= 10) {
			int y = (x % d) * dd + x / d;
			if (y > x)
				u.push_back(y);
		}
		sort(u.begin(), u.end());
		u.erase(unique(u.begin(), u.end()), u.end());
	}
	for (int t = 0; t != T; ++t) {
		int A, B, res = 0;
		cin >> A >> B;
		for (int x = A; x <= B; ++x) {
			vector<int>& u = v[x];
			vector<int>::iterator it = upper_bound(u.begin(), u.end(), B);
			res += (it - u.begin());
		}
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}

