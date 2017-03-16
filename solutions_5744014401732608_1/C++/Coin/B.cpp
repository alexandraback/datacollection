#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using LL = long long;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, kase = 0;
	cin >> T;
	while (++kase <= T) {
		cout << "Case #" << kase << ": ";
		LL B, M;
		cin >> B >> M;
		LL maxm = 1;
		for (int i = 0; i < B - 2; i++)
			maxm *= 2;
		if (M > maxm) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		int map[60][60] = {};
		map[0][B - 1] = 1;
		M--;
		LL base = 1;
		LL cur = B - 2;
		while (cur>=0 && M) {
			map[0][cur] = 1;
			for (LL i = base / 2, j = cur+1; i > 0; i /= 2, j++) {
				if (M > i) {
					M -= i;
					map[cur][j] = 1;
				}
			}
			if (M) {
				map[cur][B - 1] = 1;
				M -= 1;
			}
			base *= 2;
			cur--;
		}
		map[0][0] = 0;
	//	cout << "Case #" << kase << ": ";
		//if (M != 0) cout << "IMPOSSIBLE" << endl;
	//	else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					cout << map[i][j];
				}
				cout << endl;
			}
	//	}
	}
	return 0;
}