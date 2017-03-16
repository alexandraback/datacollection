#include <map>
#include <cstdlib>
#include <iostream>
using namespace std;

int r, n, m, k, u;
int a[12], b[12], c[12], f[13];
bool flag, sub;

void dfs2(int i, int result, int product) {
	if (sub || result == product) {
		sub = true;
		return;
	}
	if (i < n) {
		dfs2(i + 1, result, product);
		dfs2(i + 1, result, product * a[i]);
	}
}

int fu(int a[]) {
	map<int, int> counter;
	for (int i = 0; i < n; ++i) {
		counter[a[i]]++;
	}
	int k = f[n];
	for (map<int, int>::iterator i = counter.begin(); i != counter.end(); ++i) {
		k /= f[i->second];
	}
	return k;
}

void dfs(int i) {
	if (i == n) {
		for (int j = 0; j < k; ++j) {
			sub = false;
			dfs2(0, b[j], 1);
			if (!sub) {break;}
		}
		if (sub == true && fu(a) > u) {
			for (int j = 0; j < n; ++j) {c[j] = a[j];}
		}
	} else {
		for (int j = 2; j <= m && !flag; ++j) {
			a[i] = j;
			dfs(i + 1);
		}
	}
}

int main() {
	srand(time(0));
	int T;
	cin >> T;
	cin >> r >> n >> m >> k;
	cout << "Case #1:\n";
	f[0] = 1;
	for (int i = 1; i <= 12; ++i) {f[i] = f[i - 1] * i;}
	while (r--) {
		for (int i = 0; i < k; ++i) {cin >> b[i];}
		flag = false;
		u = -1;
		for (int i = 0; i < n; ++i) {c[i] = rand() % (m - 1) + 2;}
		dfs(0);
		for (int i = 0; i < n; ++i) {cout << c[i];}
		cout << "\n";
	}
}
