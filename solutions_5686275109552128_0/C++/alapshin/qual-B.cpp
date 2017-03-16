#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define ST first
#define ND second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxd = 1200;

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int d;
		int p[maxd];
		int maxp = 0;

		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> p[j];
			maxp = max(maxp, p[j]);
		}

		int best = maxp;
		for (int j = 1; j <= maxp; j++) {
			int tt = 0;
			for (int k = 0; k < d; k++) {
				tt += (p[k] + j - 1) / j - 1;
			}
			if (tt + j < best) {
				best = tt + j;
			}
		}

		cout << "Case #" << i + 1 << ": " << best << endl;
	}

	return 0;
}


