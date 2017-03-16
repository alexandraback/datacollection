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
#include <time.h>
#include <memory.h>
#include <sstream>

using namespace std;

const long long inf = 2 * 1000 * 1000 * 1000;
long long a[111][111];
long long rw[11111];
long long cl[11111];
long long rr[11111];
long long cc[11111];
long long xx[11111];
long long tp[11111];

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	long long tests;
	cin >> tests;
	for (long long test = 1; test <= tests; test++) {
		long long b, m;
		cin >> b >> m;

		cout << "Case #" << test << ": ";
		long long cur = (1LL << (b - 2));
		if (m > cur) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			bool a[55][55];
			memset(a, false, sizeof(a));
			cout << "POSSIBLE" << endl;
			cur /= 2;
			for (long long i = 2; i < b; i++) {
				for (long long j = i + 1; j <= b; j++) {
					a[i][j] = true;
				}
			}
			for (long long num = 2; num <= b; num++) {
				if (m >= cur) {
					a[1][num] = true;
					m -= cur;
				}
				cur /= 2;
				cur = max(1LL, cur);
			}

			for (long long i = 0; i < b; i++) {
				for (long long j = 0; j < b; j++) {
					cout << (a[i + 1][j + 1] ? 1 : 0);
				}
				cout << endl;
			}
		}
	}

	//system("pause");
	return 0;
}