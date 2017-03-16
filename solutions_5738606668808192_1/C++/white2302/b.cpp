//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define bll __int128_t
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

vector <ll> ans;

ll prime(bll x) {
	for (ll i = 2; i <= 1000; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			return i;
		}
	}

	return 1;
}

ll check(bll x, int o) {
	bll f = 1;

	bll y = 0;

	while (x != 0) {
		y += (x & 1) * f;
		f *= o;
		x >>= 1;
	}

	return prime(y);
}

bool check(bll x) {
	ans.clear();
	if ((x & 1) == 0) {
		return false;
	}

	for (int i = 2; i <= 10; i++) {
		if (check(x, i) == 1) {
			return false;
		}
	}

	return true;
}

void write(bll x) {
	if (x == 0) {
		return;
	}

	write(x >> 1);
	cout << (int)(x & 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	int n, m;

	cin >> n >> m;

	for (bll i = ((ll)1 << (n - 1)); m > 0; i++) {
		if (check(i)) {
			write(i);
			for (int j = 0; j < (int)ans.size(); j++) {
				cout << ' ' << ans[j];
			}
			cout << endl;
			m--;
		}
	}

	return 0;
}
