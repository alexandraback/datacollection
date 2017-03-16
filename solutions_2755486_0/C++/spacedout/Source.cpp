#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>

#include <vector>
#define mp make_pair

using namespace std;

struct el {

	int x, y;
	int d, p;

	el () {}
	el (int _x, int _y, int _d, int _p) : x(_x), y(_y), d(_d), p(_p){}
};

vector<el> all;

bool cmp (el p1, el p2) {

	return p1.d < p2.d;
}

int h[10000];

void solve () {

	memset (h, 0, sizeof(h));
	all.clear();

	int n;
	scanf ("%d", &n);

	for (int i = 0; i < n; ++i) {
	
		int d;
		int ni, w, e, power, days, dist, s;

		scanf ("%d%d%d%d%d%d%d%d", &d, &ni, &w, &e, &power, &days, &dist, &s);

		int x = w, y = e;

		for (int j = 0; j < ni; ++j) {
		
			x += dist; y += dist;
			d += days;
			power += s;

			all.push_back( el(x, y, d, power) );
		}
	}

	sort (all.begin(), all.end(), cmp);
	int ans = 0;

	for (int i = 0; i < (int)all.size(); ) {
	
		//printf ("hit day: %d at %d %d power %d\n", all[i].d, all[i].x, all[i].y, all[i].p);

		int j;
		for (j = i; j < (int)all.size() && all[j].d == all[i].d; ++j) {
		
			for (int k = all[j].x; k <= all[j].y; ++k)
				if (h[k+400] < all[j].p) {
					ans++;
					break;
				}
		}

		for (j = i; j < (int)all.size() && all[j].d == all[i].d; ++j) {
		
			for (int k = all[j].x; k <= all[j].y; ++k)
				if (h[k+400] < all[j].p) {
					h[k+400] = all[j].p;
					//break;
				}
		}

		i = j;
	}

	static int testN = 1;
	cout << "Case #" << testN << ": " << ans <<"\n";
	testN++;
}

int main () {

	int t;
	scanf ("%d", &t);

	for (; t; t--) solve();

	return 0;
}
