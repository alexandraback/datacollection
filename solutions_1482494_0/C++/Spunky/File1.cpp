// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

struct my {
	int c, p, r;
};

int func(my a, my b) {
	if (a.c == b.c) {
		return (a.r > b.r);
	}
	return (a.c < b.c);
}

int main() {
	ifstream cin("B-small-attempt5.in");
	ofstream cout("A.out");
	int t;

	cin >> t;

	for (int u = 0; u < t; u++) {
		int n;
		cin >> n;
		vector<my>one(n);
		vector<my>two(n);
		int count = 0;
		int stars = 0;
		int tt = 0;
		for (int i = 0; i < n; i++) {
			cin >> one[i].c >> two[i].c;
			one[i].p = i;
			two[i].p = i;
			one[i].r = two[i].c;
			two[i].r = 0;

		}

		sort(one.begin(), one.begin() + n, func);
		sort(two.begin(), two.begin() + n, func);
		int max = 2001002;
		int it = 0, io = 0;
		vector <int> col(1000, 0);
		while (tt != n) {

			while (it < n && two[it].c <= stars) {
				tt++;
				count++;
				if (col[two[it].p] == 0) {
					stars += 2;
				} else {
					stars++;
				}
				col[two[it].p] = 1;
				two[it].c = max;

				it++;
			}

			if (tt != n) {
				while (io < n && two[it].c > stars && one[io].c <= stars) {
					if (col[one[io].p] == 1) {
						one[io].c = max;
						io++;
						continue;
					}
					count++;
					stars += 1;
					one[io].c = max;
					col[one[io].p] = 1;
					io++;


				}
				if (two[it].c > stars) {
					break;
				}
			}
		}

		cout << "Case #" << u + 1 << ": ";
		if (tt == n) {
			cout << count;
		}
		else {
			cout << "Too Bad";
		}
		cout << endl;

	}
	return 0;
}
// ---------------------------------------------------------------------------
