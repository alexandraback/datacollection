#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	freopen("A-small.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int t; cin >> t;

	for (int e=1; e<=t; e++) {
		int n; cin >> n;

		int s[222]; for (int i=0; i<n; i++) cin >> s[i];
		int mx = -1, mxpos;

		for (int i=0; i<n; i++) {
			if (s[i] > mx) {
				mx = s[i];
				mxpos = i;
			}
		}

		int mx2 = -1;
		for (int i=0; i<n; i++) {
			if (mxpos == i) continue;
			if (s[i] > mx2)
				mx2 = s[i];
		}

		double sum = std::accumulate(s, s+n, 0);

		cout << "Case #" << e << ": ";

		for (int i=0; i<n; i++) {
			double mn = 0;
			double mx = 1;
			for (int u=0; u<88; u++) {
				double md = (mn + mx) * 0.5;
				double myPoints = s[i] + sum * md;
				double lft = 1 - md;

				bool can = true;
				for (int t=0; t<n; t++) {
					if (t == i) continue;
					double need = (myPoints - s[t]) / sum;
					if (need <= 0) continue;
					lft -= need;
					if (lft < -1e-12) {
						can = false;
						break;
					}
				}

				if (can) mn = md;
				else mx = md;
			}
			cout << fixed << setprecision(8) << (mn + mx) * 50 << ' ';
		}

		cout << endl;
	}

	return 0;
}
