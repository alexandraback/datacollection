

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second

static void solve();

int main() {
	freopen("D.in.txt","r",stdin);
	freopen("D.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static void solve() {
	int x, r, c;
	cin >> x >> r >> c;
	if (r > c)
		swap(r, c);
	bool tile = r * c % x == 0;
	if (x > 2 && r == 1)
		tile = false;
	if (tile) {
	switch (x) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			if (r == 1)
				tile = false;
			break;
		case 4:
			if (r <= 2)
				tile = false;
			break;
		case 5:
			if (r <= 3)
				tile = false;
			break;
		case 6:
			if (r <= 3)
				tile = false;
			break;
		default:
			tile = false;
	}
	}
	
	cout << (tile ? "GABRIEL" : "RICHARD");
}

#endif

