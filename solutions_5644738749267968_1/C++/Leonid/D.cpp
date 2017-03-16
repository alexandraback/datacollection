#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("D-large.in", "rt", stdin);
	//freopen("test.out", "wt", stdout);
#endif
}

void solve() {
	int n; scanf("%d ", &n);
	vector<double> v(n), w(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf ", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf ", &w[i]);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	int i1 = 0, i2 = n - 1, j1 = 0, j2 = n - 1;
	int score1 = 0, score2 = 0;
	while (i2 >= i1) {
		if (v[i2] > w[j2]) {
			i2--;
			j1++;
			score1++;
		} else {
			i2--;
			j2--;
		}
	}

	i1 = 0, i2 = n - 1, j1 = 0, j2 = n - 1;
	while (j2 >= 0 && v[i2] < w[j2]) {
		j2--;
		i1++;
	}
	while (i1 <= i2) {
		if (v[i1] > w[j1]) {
			score2++;
			j1++;
		}
		i1++;
	}

	static int ntest = 0;
	cout << "Case #" << ++ntest << ": " << score2 << " " << score1 << endl;
}




int main() {
	openFiles();
	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) solve();

	return 0;
}
