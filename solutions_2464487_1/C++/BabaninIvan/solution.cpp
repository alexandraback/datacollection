#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int64 solve() {
	int64 t, rad;
	cin >> rad >> t;
	if (2LL * rad + 1LL > t)
		return 0;
	int64 sum = 0;
	for (int64 i = 1; i <= 100000; ++i) {
		sum += int64(2) * rad + int64(1) + int64(4) * (i - int64(1));
		if (sum > t)
			return i - 1;
	}
	int64 l = 100000;
	int64 r = int64(2) * int64(1000000000);
	while (r - l > int64(100)) {
		int64 m = (l + r) / int64(2);
		if (2 * m * m > t)
			r = m;
		else {
			if ((int64(2) * m * m + (int64(2) * rad - int64(1)) * m) > t)
				r = m;
			else l = m;
		}
	}
	for (int64 i = l; i <= r; ++i)
		if ((int64(2) * i * i + (int64(2) * rad - int64(1)) * i) > t)
			return i - 1;
	return r;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		cout << solve() << endl;
	}
	return 0;
}