/*
 * C.cpp
 *
 *  Created on: Apr 27, 2013
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

vector<int> p, v;
int R, N, M, K;
map<vector<int>, double> res;

void form() {
	if (SZ(v) == N) {
		vector<int> nv = v;
		sort(nv.begin(), nv.end());

		map<int, int> frq;
		for (int i = 0; i < (1 << SZ(v)); i++) {
			int prod = 1;
			for (int j = 0; j < SZ(v); j++)
				if ((i >> j) & 1)
					prod *= v[j];

			frq[prod]++;
		}

		double pr = 0;
		for (int i = 0; i < K; i++)
			pr += (frq[p[i]] * 1. / (1 << SZ(v)));

		res[nv] += (pr / K);
		return;
	}

	for (int i = 2; i <= M; i++) {
		v.push_back(i);
		form();
		v.pop_back();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif
	int T;
	cin >> T;

	for (int tt = 0; tt < T; tt++) {
		cout << "Case #" << tt + 1 << ": " << endl;

		cin >> R >> N >> M >> K;

		for (int r = 0; r < R; r++) {
			v.clear();
			p.clear();
			res.clear();
			for (int i = 0; i < K; i++) {
				int a;
				cin >> a;
				p.push_back(a);
			}

			form();

			pair<vector<int>, double> bst = MP(vector<int>(), 0);
			for (__typeof(res.begin()) it = res.begin(); it != res.end();
					it++) {
				if (it->second > bst.second)
					bst = MP(it->first, it->second);

//				for (int i = 0; i < SZ(it->first); i++)
//					cout << it->first[i];
//				cout << " - > " << it->second << endl ;
			}

			for (int i = 0; i < SZ(bst.first); i++)
				cout << bst.first[i];
			cout << endl ;
		}
	}
	return 0;
}
