/*
 * c.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

bool solve(vector<int> &v, int &m1, int &m2) {
	int sum = 0, n = v.size();
	forn(i, n)
		sum += v[i];
	vector<int> mask(sum + 1, 0);
	forn(subset, 1 << n) {
		int tmp = 0;
		forn(i, n)
			if ((1 << i) & subset)
				tmp += v[i];
		if (mask[tmp] != 0) {
			m1 = subset;
			m2 = mask[tmp];
			return true;
		}
		mask[tmp] = subset;
	}
	return false;
}

int main(void) {
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c) {
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i, n)
			cin >> v[i];
		sort(v.begin(), v.end());
		int m1, m2;
		bool ans = solve(v, m1, m2);
		printf("Case #%d:\n", c);
		if (not ans)
			printf("Impossible\n");
		else {
			forn(i, v.size())
				if ((1 << i) & m1) {
					printf("%d", v[i]);
					if (i + 1 != (int) v.size())
						printf(" ");
				}
			printf("\n");
			forn(i, v.size())
				if ((1 << i) & m2) {
					printf("%d", v[i]);
					if (i + 1 != (int) v.size())
						printf(" ");
				}
			printf("\n");
		}
	}
	return 0;
}
