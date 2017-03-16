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

int n;
bool used[4000];
bool used2[4000];
int a1[4000];
int a2[4000];
vector <pair <int, pair <int, bool> > > a;
vector <int> c;
set <pair <int, int> > b;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		used[i] = used2[i] = false;
	a.clear();
	b.clear();
	c.clear();
	int res = 0;
	int kol = 0; 
	int num = 0;

	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		a1[i] = x;
		a2[i] = y;
		a.pb(mp(x, mp(i, false)));
		a.pb(mp(y, mp(i, true)));
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	while (kol < n) {
		while (c.size() != 0) {
			int x = c[c.size() - 1];
			c.pop_back();
			++res;
			++kol;
			++num;
			if (!used2[x])
				++res;
			used2[x] = used[x] = true;
		}
		if (kol == n)
			break;

		while ((a.size()) && (res >= a[a.size() - 1].first)) {
			if (a[a.size() - 1].second.second)
				c.pb(a[a.size() - 1].second.first);
			else b.insert(mp(a2[a[a.size() - 1].second.first], a[a.size() - 1].second.first));
			a.pop_back();
		}
		if (c.size())
			continue;
		if (b.size() == 0)
			break;
		
		int x = (*b.rbegin()).second;
		b.erase(mp(a2[x], x));

		if (used[x])
			continue;
		++res;
		++num;
		used2[x] = true;
	}

	if (kol == n)
		printf("%d\n", num);
	else printf("Too Bad\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}