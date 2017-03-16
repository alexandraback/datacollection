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

using namespace std;

int n;
int d, c, v;

vector<pair<int, int> > vv;
int solve() {
	vv.clear();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d >> c >> v;
		for (int j = 0; j < c; ++j) {
			vv.push_back(make_pair(d, -v - j));
		}
	}
	if (vv.size() < 2) {
		return 0;
	}
	sort(vv.begin(), vv.end());
	if (vv[0].second == vv[1].second)
		return 0;
	int d1 = vv[0].first;
	int d2 = vv[1].first;
	int v1 = -vv[0].second;
	int v2 = -vv[1].second;
	if (d1 > d2) {
		int l1 = 360 - d2 + d1;
		int l2 = 360 - d1;
		if (l1 / (360.0 * (1.0 / d2 - 1.0 / d1)) <= l2 * d1 / 360.0)
			return 1;
		else
			return 0;
	}
	else {
		int l1 = 360 + d2 - d1;
		int l2 = 360 - d2;
		if (l1 / (360.0 * (1.0 / d1 - 1.0 / d2)) <= l2 * d2 / 360.0)
			return 1;
		else
			return 0;
	}
}

int main() {
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}
	return 0;
}


