#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <list>
#include <memory.h>

using namespace std;

int a[30];

void solve() {
	int n;
	string x[30], y[30];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	for (int i = 0; i < a[n]; ++i) {
		int t = 0;
		bool f = true;
		for (int j = 0; j < n; ++j) {
			if ((i & a[j]) > 0) {
				++t;
				bool f1 = false, f2 = false;
				for (int k = 0; k < n; ++k) {
					if ((i & a[k]) == 0) {
						if (x[j] == x[k]) {
							f1 = true;
						}
						if (y[j] == y[k]) {
							f2 = true;
						}
					}
				}
				if (!f1 || !f2) {
					f = false;
				}
			}
		}
		if (f && ans < t) {
			ans = t;
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	a[0] = 1;
	for (int i = 1; i < 20; ++i) {
		a[i] = a[i - 1] * 2;
	}
	
	for (int i = 0; i < n; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	
	return 0;
}

