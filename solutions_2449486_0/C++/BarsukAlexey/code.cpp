#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma comment(linker, "/STACK:64000000")

int t;
int n, m;
int f[105][105];
int c[105], r[105];
int a[105][105];

void determinate() {
	for (int i = 0; i < n; i++) {
		r[i] = -1e9;
	}
	for (int j = 0; j < m; j++) {
		c[j] = -1e9;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r[i] < f[i][j]) r[i] = f[i][j];
			if (c[j] < f[i][j]) c[j] = f[i][j];
		}
	}
}
void doSomething() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = c[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > r[i]) a[i][j] = r[i];
		}
	}
}
bool isOk() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != f[i][j]) 
				return false;
		}
	}
	return true;
}
int main() {
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &f[j][k]);
				a[j][k] = 100;
			}
		}
		determinate();
		doSomething();
		cout << "Case #" << i + 1 << ": ";
		if (isOk()) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}