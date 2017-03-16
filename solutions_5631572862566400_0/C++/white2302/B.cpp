#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = 1010;

vector <int> ed[maxn];
bool used[maxn];
int v[maxn];

int get_cycle(int x, int y) {
	used[x] = true;

	if (v[x] == y) {
		return 1;
	}

	if (used[v[x]]) {
		return 0;
	}

	int ans = get_cycle(v[x], y);

	if (ans != 0) {
		return ans + 1;
	}

	return 0;
}

int bf(int x, int y) {
	int res = 0;

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i];

		if (u != y) {
			res = max(res, bf(u, y));
		}
	}

	return res + 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;
	int f = 0;

	while (t--) {
		f++;
		cout << "Case #" << f << ": ";

		int n;

		cin >> n;

		for (int i = 1; i <= n; i++) {
			ed[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			int x;

			scanf("%d", &x);
			v[i] = x;

			ed[x].push_back(i);
		}

		int ans = 0;

		for (int i = 1; i <= n; i++) {
			memset(used, 0, sizeof used);
			if (!used[i]) {
				ans = max(ans, get_cycle(i, i));
			}
		}

		int res = 0;

		for (int i = 1; i <= n; i++) {
			if (v[v[i]] == i) {
				res += bf(i, v[i]);
			}
		}

		ans = max(ans, res);

		cout << ans << endl;
	}

	return 0;
}
