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
vector< vector <int64> > a;
int sz = 0;
vector <int64> dfs;

void perebor(int pos, int last) {
	if (pos == n) {
		a.pb(dfs);
		a[sz].pb(0);
		for (int i = 0; i < n; ++i)
			a[sz][0] = a[sz][0] * 10LL + int64(cur[i]);
		vector <int64> tmp;
		tmp.clear();
		for (int j = 0; j < (1 << n); ++j) {
			int64 pr = 1;
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
	for (int j = last; j <= m; ++j) {
		cur.pb(j);
		perebor(pos + 1, j);
		cur.pop_back();
	}
}

int64 b[20];

void solve() {
	scanf("%d %d %d %d", &r, &n, &m, &k);
	srand(45);
	perebor(0, 2);
	sz = a.size();
	for (int z = 0; z < r; ++z) {
		for (int i = 0; i < k; ++i)
			cin >> b[i];

		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		
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
				cout << a[i][0] << endl;
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