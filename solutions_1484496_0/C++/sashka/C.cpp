#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 1 << 5;
const int cmax = 1 << 20;

map<int, vector<int> > mp;
int a[nmax];
int n;

void print(int i) {
	int cnt = 0;

	for(int j = 0; j < n; ++j) {
		if (i & (1 << j)) { 
			++cnt;
		}
	}

	for(int j = 0; j < n; ++j) {
		if (i & (1 << j)) {
			--cnt;
			printf("%d%c", a[j], cnt ? ' ' : '\n');
		}
	}

}

void solveTest() {

	int lim = 1 << n;

	mp.clear();

	for(int i = 1; i < lim; ++i) {

		int s = 0;

		for(int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				s += a[j];
			}
		}

		map<int, vector<int> >::iterator it = mp.find(s);

		if (it == mp.end()) {
			mp[s] = vector<int>();
			it = mp.find(s);
		}
		it->second.push_back(i);

	}

	map<int, vector<int> >::const_iterator ce = mp.end();

	int mx = 0;

	for(map<int, vector<int> >::const_iterator cit = mp.begin(); cit != ce; ++cit) {

		int m = cit->second.size();
		mx = max(mx, m);
	}

	for(map<int, vector<int> >::const_iterator cit = mp.begin(); cit != ce; ++cit) {

		int m = cit->second.size();

		for(int i = 0; i < m; ++i) {
			for(int j = i + 1; j < m; ++j) {
				int x = cit->second[i];
				int y = cit->second[j];
				int z = x & y;
				x = x ^ z;
				y = y ^ z;
				if (x && y) {
					print(x);
					print(y);
					return;
				}
			}
		}

	}

	puts("Impossible");

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in", "rt", stdin);
	freopen("C.out", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		printf("Case #%d:\n", tt + 1);
		solveTest();
		cerr << "Case " << tt + 1 << " done\n";
	}
	return 0;
}
