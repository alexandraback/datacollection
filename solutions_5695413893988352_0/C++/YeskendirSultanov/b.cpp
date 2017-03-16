#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int T, id;
string a, b;

void solve() {
	id++;
	cout << "Case #" << id << ": ";
	cin >> a >> b;
	int md = 10000;
	int C = 1000, J = 2000;
	int n = a.size();

	if (n == 1) {
		if (a[0] == b[0] && a[0] == '?') {
			cout << "0 0" << endl;
		} else if (a[0] == '?') {
			cout << b[0] << ' ' << b[0] << endl;
		} else {
			cout << a[0] << ' ' << a[0] << endl;
		}
		return;
	} else if (n == 2) {
		for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j) {
			bool ok = true;
			if (a[0] != '?' && a[0] - '0' != i / 10)
				ok = false;
			if (a[1] != '?' && a[1] - '0' != i % 10)
				ok = false;
			if (b[0] != '?' && b[0] - '0' != j / 10)
				ok = false;
			if (b[1] != '?' && b[1] - '0' != j % 10)
				ok = false;

			if (ok) {
				if (abs(i - j) < md) {
					md = abs(i - j);
					C = i;
					J = j;
				} else if (abs(i - j) == md) {
					if (i < C) {
						C = i;
						J = j;
					} else if (i == C && j < J) {
						C = i;
						J = j;
					}
				}
			}
		}
		cout << C / 10 << C % 10 << ' ' << J / 10 << J % 10 << endl;
		return;
	} else {
		for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j) {
			bool ok = true;
			if (a[0] != '?' && a[0] - '0' != i / 100)
				ok = false;
			if (a[1] != '?' && a[1] - '0' != (i % 100) / 10)
				ok = false;
			if (a[2] != '?' && a[2] - '0' != i % 10) 
				ok = false;
			if (b[0] != '?' && b[0] - '0' != j / 100)
				ok = false;
			if (b[1] != '?' && b[1] - '0' != (j % 100) / 10)
				ok = false;
			if (b[2] != '?' && b[2] - '0' != j % 10) 
				ok = false;

			if (ok) {
				if (abs(i - j) < md) {
					C = i;
					J = j;
					md = abs(i - j);
				} else if (abs(i - j) == md && i < C) {
					C = i;
					J = j;
				} else if (abs(i - j) == md && (i == C && j < J)) {
					C = i;
					J = j;
				}
			}		
		}
		cout << C / 100 << (C % 100) / 10 << C % 10 << ' ' << J / 100 << (J % 100) / 10 << J % 10 << endl;
		return;	
	}

}

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	cin >> T;

	while (T--) {
		solve();
	}


	return 0;
}
                                

