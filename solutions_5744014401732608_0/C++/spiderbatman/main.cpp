#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

#define INF 2000000000
#define MOD 1000000000

using namespace std;

int main() {
	int testCnt;
	cin >> testCnt;
	for (int testNum = 1; testNum <= testCnt; testNum++) {
		cout << "Case #" << testNum << ": ";
		long long b, m;
		cin >> b >> m;
		bool ans[50][50];
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				ans[i][j] = false;
		long long full = 0;
		long long cur = 1;
		bool isGood = false;
		if (m == 1) {
			cout << "POSSIBLE" << endl;
			ans[0][b - 1] = true;
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++)
					cout << ans[i][j];
				cout << endl;
			}
			continue;
		}
		for (int i = 0; i < b - 2; i++) {
			cur *= 2;
			if (cur >= m) {
				if (cur == m)
					full = i + 1;
				else
					full = i;
				isGood = true;
				break;
			}
		}
		if (!isGood) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		long long tmp = 1;
		for (int i = 0; i <= full; i++) {
			for (int j = i + 1; j <= full; j++) {
				ans[i][j] = true;
			}
			ans[i][b - 1] = true;
		}
		tmp = (1 << full);
		m -= tmp;
		for (int j = 0; j < 64; j++) {
			if ((1LL << j) & m) {
				ans[j + 1][full + 1] = true;
				ans[full + 1][b - 1] = true;
			}
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < b; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
