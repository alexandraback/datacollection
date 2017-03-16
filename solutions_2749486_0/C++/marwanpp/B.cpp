/*
 * B.cpp
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

struct state {
	string path;
	int x, y;

	state(int cx, int cy, string s) {
		x = cx;
		y = cy;
		path = s;
	}
};

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
string d = "EWNS";

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

		int x, y;
		cin >> x >> y;

		queue<state> q;
		set<pii> vis;

		q.push(state(0, 0, ""));
		vis.insert(MP(0, 0));

		int step = 1;
		while (SZ(q)) {
			int sz = SZ(q);

			while (sz--) {
				state f = q.front();
				q.pop();

				for (int i=0 ; i < 4 ; i++) {
					int nx = f.x + dx[i] * step ;
					int ny = f.y + dy[i] * step ;

					if (nx == x && ny == y) {
						cout << f.path + d[i] << endl ;
						goto Next ;
					}
					if (vis.insert(MP(nx,ny)).second)
						q.push(state (nx,ny,f.path + d[i]));
				}
			}

			step++;
		}

		cout << "----------------------------------" << endl ;
		Next:;
	}

	return 0;
}
