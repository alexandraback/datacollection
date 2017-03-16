#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;
typedef __int128_t lll;

using namespace std;



lll prime(lll x) {
	for (lll i = 2; i * i <= x && i < 100; ++i) {
		if (x % i == 0)
			return i;
	}
	return 0;
}


int main() {
	int n, m;
	cin >> n;
	cin >> n >> m;
	cout << "Case #1:\n";

	lll l = (1ll << (n - 1)) + 1;
	lll r = (1ll << n);
	for (lll i = l; i < r && m > 0; i += 2) {
		int fl = 0;
		vector<lll> vv;
		for (int j = 2; j <= 10; ++j) {
			lll k = 0;
			for (int x = n - 1; x >= 0; --x) {
				k *= j;
				if ((i >> x) & 1)
					++k;
			}
			lll x = prime(k);
			if (x == 0) {
				fl = 1;
				break;
			}
			vv.push_back(x);
		}
		if (fl)
			continue;
		--m;
		for (int j = n - 1; j >= 0; --j)
			if ((i >> j) & 1)
				cout << 1;
			else
				cout << 0;
		for (int j = 0; j < (int)vv.size(); ++j)
			cout << " " << (ll)vv[j];
		cout << "\n";
	}
	assert(m == 0);


	return 0;
}


