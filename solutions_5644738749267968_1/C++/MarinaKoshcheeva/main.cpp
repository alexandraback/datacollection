#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2010;

int n;
double a[MAXN];
double b[MAXN];
pair<double, int> c[MAXN];

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c[i] = make_pair(a[i], -1);
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		c[i + n] = make_pair(b[i], 1);
	}

	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + 2 * n);

	int res = 0;
	int balance = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (c[i].second == -1 && balance > 0) {
			res++;
			balance--;
		}
		if (c[i].second == 1) {
			balance++;
		}
	}

	cout << res << " ";

	res = 0;
	balance = 0;
	for (int i = 2 * n - 1; i >= 0; --i) {
		if (c[i].second == -1) {
			if (balance == 0)
				res++;
			else
				balance--;
		}
		else {
			balance++;
		}
	}

	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
