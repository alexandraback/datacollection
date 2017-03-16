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


int d[1200];
int n;


bool check(int x) {
	for (int q = 0; q < x; ++q) {
		int now = 0;
		for (int i = 0; i < n; ++i)
			now += (d[i] - 1) / (x - q);
		if (now <= q)
			return true;
	}
	return false;
}

int solve() {
	int l = 0;
	int r = 1001;
	while (r - l > 1) {
		int x = (l + r) >> 1;
		if (check(x))
			r = x;
		else
			l = x;
	}
	return r;
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> d[j];
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}
	return 0;
}


