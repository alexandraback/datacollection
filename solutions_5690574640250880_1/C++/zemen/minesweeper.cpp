#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "minesweeper"

char a[100][100];
char rot;
int n, m;

void fix() {
	if (!rot)
		return;
	for (int i = 0; i < max(n, m); ++i)
		for (int j = 0; j < max(n, m); ++j)
			if (i < j)
				swap(a[i][j], a[j][i]);
	swap(n, m);
}

void solve(int test) {
	cout << "Case #" << test << ":\n";
	int k;
	cin >> n >> m >> k;
	k = n * m - k;
	rot = (n > m);
	if (n > m)
		swap(n, m);
	if (n == 1) {
		for (int i = 1; i < k; ++i)
			a[0][i] = '.';
		for (int i = k; i < m; ++i)
			a[0][i] = '*';
		a[0][0] = 'c';
	} else if (k == 1) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = '*';
		a[0][0] = 'c';
	} else if (k == 2 || k == 3) {
		cout << "Impossible\n";
		return;
	} else if (n == 2) {
		if (k % 2) {
			cout << "Impossible\n";
			return;
		} else {
			for (int i = 0; i < k / 2; ++i)
				a[0][i] = a[1][i] = '.';
			for (int i = k / 2; i < m; ++i)
				a[0][i] = a[1][i] = '*';
			a[0][0] = 'c';
		}
	} else if (k == 5 || k == 7) {
		cout << "Impossible\n";
		return;
	} else if (k >= 2 * (n + m) - 4) {
		for (int i = 0; i < n; ++i)
			a[i][0] = a[i][1] = '.';
		for (int i = 0; i < m; ++i)
			a[0][i] = a[1][i] = '.';
		k -= 2 * (n + m) - 4;
		for (int i = 2; i < n; ++i)
			for (int j = 2; j < m; ++j) {
				if (k) {
					a[i][j] = '.';
					--k;
				} else
					a[i][j] = '*';
			}
		a[0][0] = 'c';
	} else {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = '*';
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				a[i][j] = '.';
		k -= 4;
		if (k % 2) {
			a[0][2] = a[1][2] = a[2][2] = a[2][1] = a[2][0] = '.';
			k -= 5;
			for (int i = 3; i < n && k; ++i) {
				a[i][0] = a[i][1] = '.';
				k -= 2;
			}
			for (int i = 3; i < m && k; ++i) {
				a[0][i] = a[1][i] = '.';
				k -= 2;
			}
		} else {
			for (int i = 2; i < n && k; ++i) {
				a[i][0] = a[i][1] = '.';
				k -= 2;
			}
			for (int i = 2; i < m && k; ++i) {
				a[0][i] = a[1][i] = '.';
				k -= 2;
			}
		}
		
		a[0][0] = 'c';
	}
	fix();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][j];
		cout << '\n';
	}
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int tn;
	cin >> tn;
	for (int i = 0; i < tn; ++i)
		solve(i + 1);
}
