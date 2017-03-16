#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, m;
int a[200][200];
bool b[200];
bool c[200];
vector <pair <int, pair <int, int> > > d;

bool solve() {
	scanf("%d %d", &n, &m);
	d.clear();
	for (int i = 0; i < 150; ++i)
		b[i] = c[i] = false;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			d.pb(mp(a[i][j], mp(i, j)));
		}
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	int p1, p2;
	p1 = p2 = 0;
	while (p1 < d.size()) {
		p2 = p1;
		while ((p2 < d.size()) && (d[p2].first == d[p1].first))
			++p2;
		for (int i = p1; i < p2; ++i)
			if (b[d[i].second.first] && c[d[i].second.second])
				return false;
		for (int i = p1; i < p2; ++i)
			b[d[i].second.first] = c[d[i].second.second] = true;
		p1 = p2;
	}
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		bool f = solve();
		if (f)
			printf("Case #%d: YES\n", i + 1);
		else printf("Case #%d: NO\n", i + 1);
	}
	return 0;
}