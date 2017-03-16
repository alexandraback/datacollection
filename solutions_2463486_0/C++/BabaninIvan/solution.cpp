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

vector <int64> a;

bool fair(int64 x) {
	a.clear();
	int64 y = x;
	while (y) {
		a.pb(y % int64(10));
		y /= int64(10);
	}
	for (int i = 0; i < a.size(); ++i)
		y = y * int64(10) + a[i];
	if (y == x)
		return true;
	return false;
}

vector <int64> res;

void precalc() {
	for (int64 i = 1; i <= 10000000; ++i)
		if (fair(i) && fair(i * i)) {
			res.pb(i * i);
		}
}

int solve() {
	int l, r;
	scanf("%d %d", &l, &r);
	int ans = 0;
	for (int i = 0; i < res.size(); ++i)
		if ((res[i] >= l) && (res[i] <= r))
			++ans;
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	precalc();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: %d\n", i + 1, solve());
	}
	return 0;
}