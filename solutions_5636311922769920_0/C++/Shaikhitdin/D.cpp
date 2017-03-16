/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 20;

bool u[N];

inline void convert (int x) {
	if (x == 0)
		u[0] = 1;
	while (x) {
		int val = x % 10;
		u[val] = 1;
		x /= 10;
	}
}

int main() {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t_num;
	cin >> t_num;

	for (int test = 1; test <= t_num; ++test) {
		cout << "Case #" << test << ": ";
		int k, c, s;
		cin >> k >> c >> s;
		if (s != k) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 1; i <= k; ++i) {
			cout << i << " ";
		}
		cout << "\n";
	}
		
	return 0;
}

