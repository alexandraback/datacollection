/*
 * A.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Marwan
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <climits>
#include <set>
#include <map>

using namespace std;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
#define MP make_pair
#define SZ(x) (int)x.size()

int dcmp(double a, double b) {
	return (fabs(a - b) <= eps) ? 0 : ((a < b) ? -1 : 1);
}

typedef long long ll;
typedef pair<int, int> pii;

pii toabsorb(int cur, int g) {
	pii res = MP(0, 0);

	while (cur <= g) {
		res.first++;
		cur += cur - 1;
	}

	res.second = cur + g;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cout << "Case #" << t + 1 << ": ";
		int A, N;
		cin >> A >> N;

		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		if (A == 1) {
			cout << SZ(v) << endl;
		} else {
			sort(v.begin(), v.end());
			int mn = SZ(v);

			int cntAdd = 0;
			for (int i = 0; i < SZ(v); i++) {
				pii cur = toabsorb(A, v[i]);
				A = cur.second;
				cntAdd += cur.first;
				mn = min(mn, cntAdd + SZ(v) - i - 1);
			}

			cout << mn << endl;
		}
	}
	return 0;
}
