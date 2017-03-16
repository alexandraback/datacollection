#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <time.h>

using namespace std;

int f[1111];
int p[20];

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");


	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> f[i + 1];
		}

		int ans = 0;

		for (int mask = 1; mask < (1 << n); mask++) {
			int sz = 0;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) != 0) {
					p[sz++] = (i + 1);
				}
			}

			do {
				int cur = 0;

				for (int i = 0; i < sz; i++) {
					int next = (i + 1 < sz ? i + 1 : 0);
					int prev = (i > 0 ? i - 1 : sz - 1);
					if (f[p[i]] == p[next] || f[p[i]] == p[prev]) {
						cur++;
					}
				}
				if (cur == sz) {
					ans = max(ans, cur);
				}
			} while (next_permutation(p, p + sz));
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	
	//system("pause");
	return 0;
}