/*
 * A.cpp
 *
 *  Created on: May 12, 2013
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

int nxt[1000009];

bool isvawel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
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

		string s;
		int n;
		cin >> s >> n;

		memset(nxt, 0, sizeof nxt);
		nxt[SZ(s) - 1] = SZ(s) - 1;
		for (int i = SZ(s) - 2; i >= 0; i--)
			nxt[i] = isvawel(s[i]) ? i : nxt[i + 1] - isvawel(s[i+1]);

		vector<int> validEnds;

		for (int i = 0; i < SZ(s); i++) {
			if (isvawel(s[i]))
				continue;

			if (nxt[i] - i + 1 >= n)
				validEnds.push_back(i);
		}

		ll ans = 0;

		for (int i = 0; i < SZ(s); i++) {
			vector <int> :: iterator it =lower_bound(validEnds.begin(), validEnds.end(), i);
			if (it == validEnds.end())
				break ;
			int nxtEnd = *it ;
			ans += SZ(s) - nxtEnd - n + 1;
		}

		cout << ans << endl;
	}
	return 0;
}
