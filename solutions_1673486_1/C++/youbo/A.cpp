#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
int const L = 100000;
int a, b;
double pr[L + 1];
double cr[L + 1];
bool readin() {
	if (!(cin >> a >> b)) {
		return false;
	}
	pr[0] = 1.0;
	for (int i = 1; i <= a; ++i) {
		cin >> pr[i];
	}
	return true;
}
double solve() {
	cr[0] = 1.0;
	for (int i = 1; i <= a; ++i) {
		cr[i] = cr[i - 1] * pr[i];
	}
	double ret = min((b - a) + 1 + (b + 1) * (1 - cr[a]), 1.0 + (b + 1));
	for (int i = 1; i <= a; ++i) {
		ret = min(ret, i + i + (b - a) + 1 + (b + 1) * (1 - cr[a - i]));
	}
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	for (int cc = 1; cc <= tc; ++cc) {
		readin();
		cout << "Case #" << cc << ": " << setprecision(7) << solve() << endl;
	}
	return 0;
}
