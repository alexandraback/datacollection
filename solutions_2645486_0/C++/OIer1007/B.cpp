#include <iostream>

#include <fstream>

#include <cstring>

#include <string>

#include <iomanip>

#include <cmath>

#include <climits>

#include <algorithm>

#include <cstdio>

#include <cstdlib>

using namespace std;



int e, r, n;

int res, ans;

int v[10005];



void dfs(int deep, int nowe) {

	if (deep >= n) {

		if (res > ans) ans = res;

		return;

	}

	for (int i = 0; i <= nowe; i++) {

		if (nowe - i + r > e) continue;

		res += i * v[deep];

		dfs(deep + 1, nowe - i + r);

		res -= i * v[deep];

	}

}

			



int main() {

	freopen("B.in", "r", stdin);

	freopen("B.out","w", stdout);

	int caset;

	cin >> caset;

	for (int l = 1; l <= caset; l++) {

		cin >> e >> r >> n;

		for (int i = 0; i < n; i++) cin >> v[i];

		ans = -1;

		res = 0;

		dfs(0, e);

		cout << "Case #" << l << ": " << ans << "\n";

	}

}

