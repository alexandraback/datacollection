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

int r, n, m, k;
vector <int> cur;
vector <int> a[1000];
int sz = 0;

void perebor(int pos) {
	if (pos == n) {
		a[sz].pb(0);
		for (int i = 0; i < n; ++i)
			a[sz][0] = a[sz][0] * 10 + cur[i];
		vector <int> tmp;
		tmp.clear();
		for (int j = 0; j < (1 << n); ++j) {
			int pr = 1;
			for (int i = 0; i < n; ++i)
				if ((1 << i) & j)
					pr *= cur[i];
			tmp.pb(pr);
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());;
		for (int i = 0; i < tmp.size(); ++i)
			a[sz].pb(tmp[i]);
		++sz;
		return ;
	}
	for (int j = 2; j <= m; ++j) {
		cur.pb(j);
		perebor(pos + 1);
		cur.pop_back();
	}
}

int b[20];

void solve() {
	scanf("%d %d %d %d", &r, &n, &m, &k);

	perebor(0);
	for (int z = 0; z < r; ++z) {
		for (int i = 0; i < k; ++i)
			scanf("%d", &b[i]);

		random_shuffle(a, a + sz);
		
		
		for (int i = 0; i < sz; ++i) {
			bool f = true;
			for (int j = 0; j < k; ++j) {
				bool f2 = false;
				for (int u = 1; u < a[i].size(); ++u)
					if (a[i][u] == b[j]) {
						f2 = true;
						break;
					}
				if (!f2) {
					f = false;
					break;
				}
			}
			if (f) {
				printf("%d\n", a[i][0]);
				break;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}