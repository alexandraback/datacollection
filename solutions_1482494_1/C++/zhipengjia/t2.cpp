#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int a[1000], b[1000];
pair<int, int> L[1000];
bool check[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d%d", &a[i], &b[i]);
			L[i] = make_pair(b[i], i);
		}
		sort(L, L + n);
		int ans = 0, tot = 0, j = 0;
		for (int i = 0; i < n; i ++) check[i] = false;
		while (j < n && L[j].first <= tot) {
			tot += 2;
			ans ++;
			check[L[j].second] = true;
			j ++;
		}
		while (j < n) {
			int maxv = 0, loc = -1;
			for (int i = 0; i < n; i ++)
				if (! check[i] && a[i] <= tot) {
					int _tot = tot + 1, _j = j;
					while (_j < n && L[_j].first <= _tot) {
						if (check[L[_j].second] || L[_j].second == i) {
							_tot ++;
						} else {
							_tot += 2;
						}
						_j ++;
					}
					if (_tot > maxv) {
						maxv = _tot;
						loc = i;
					}
				}
			if (loc == -1) break;
			tot ++;
			ans ++;
			check[loc] = true;
			while (j < n && L[j].first <= tot) {
				if (check[L[j].second]) {
					tot ++;
					ans ++;
				} else {
					tot += 2;
					ans ++;
					check[L[j].second] = true;
				}
				j ++;
			}
		}
		if (tot < 2 * n)
			printf("Case #%d: Too Bad\n", test + 1);
		else
			printf("Case #%d: %d\n", test + 1, ans);
	}
	
	return 0;
}
