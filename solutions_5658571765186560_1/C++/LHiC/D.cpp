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

bool solve(int n, int m, int x) {
	if (x >= 7)
		return false;
	if ((n * m) % x != 0)
		return false;
	if (max(n, m) < x)
		return false;
	if (x == 1 || x == 2)
		return true;
	else if (x == 3)
		return (n >= 2 && m >= 2);
	else if (x == 4)
		return (n > 2 && m > 2);
	else if (x == 5) {
		if (n > 3 && m > 3)
			return true;
		if (n < 3 || m < 3)
			return false;
		if (max(n, m) >= 10)
			return true;
		else
			return false;
	}
	else if (x == 6) {
		if (n <= 3 || m <= 3)
			return false;
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << i + 1 << ": ";
		if (!solve(r, c, x))
			cout << "RICHARD\n";
		else
			cout << "GABRIEL\n";
	}
	return 0;
}


