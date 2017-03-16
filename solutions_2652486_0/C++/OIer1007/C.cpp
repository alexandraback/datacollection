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



int tmpp, i1, i2, i3, kk[10];



bool dfs(int deep, int num, int tmpp) {

	if (tmpp == num) return true;

	if (deep >= 3) return false;

	return(dfs(deep + 1, num, tmpp * kk[deep]) || dfs(deep + 1, num, tmpp));

}



int main() {

	freopen("C.in", "r", stdin);

	freopen("C.out","w", stdout);

	int tttt;

	cin >> tttt;

	int r, m ,n ,k;

	cin >> r >> n >> m >> k;

	cout << "Case #1:\n";

	while (r > 0) {

	r--;

	bool fl;

	int v[10];

	for (int i = 0; i < k; i++) cin >> v[i];

	for (i1 = 2; i1 <= m; i1++) {

		for (i2 = 2; i2 <= m; i2++) {

			for (i3 = 2; i3 <= m; i3++) {

				fl = true;			

				kk[0] = i1;

				kk[1] = i2; kk[2] = i3;	

				for (int i4 = 0; i4 < k; i4++) {

					tmpp = 1;

					if (!dfs(0, v[i4], 1)) {

						fl = false;

						break;

					}

				}

				if (fl) {

					cout << i1 << i2 << i3 << "\n";

					break;

				}

			}

			if (fl) break;

		}

		if (fl) break;

	}

	}

	return 0;



}

