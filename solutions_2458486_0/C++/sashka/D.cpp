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

const int nmax = 1 << 20;
const int cmax = 1 << 5;
const int kmax = 1 << 8;

int p[nmax];
vector<int> v[cmax];
int t[cmax];
int mp[kmax];
int n;


void clear() {
	for(int i = 0; i < n + 1; ++i) {
		v[i].clear();
	}
}

void readTest() {

	int k;
	scanf("%d%d", &k, &n);

	for(int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		v[n].push_back(x);
	}

	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &t[i], &k);
		int x;
		for(int j = 0; j < k; ++j) {
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}

}

void addKeys(int x) {
	for(int i = 0; i < (int)v[x].size(); ++i) {
		++mp[v[x][i]];
	}
}

void initKeys() {
	memset(mp, 0, sizeof(mp));
	addKeys(n);
}

queue<int> q;

void solveTest() {

	memset(p, -1, sizeof(p));

	initKeys();

	for(int i = 0; i < n; ++i) {
		if (mp[t[i]]) {
			q.push(1 << i);
			p[1 << i] = i;
		}
	}

	while(!q.empty()) {

		int x = q.front();
		q.pop();

		initKeys();
		for(int i = 0; i < n; ++i) {
			if (x & (1 << i)) {
				addKeys(i);
				--mp[t[i]];
			}
		}

		for(int i = 0; i < n; ++i) {
			if ((x & (1 << i)) == 0 && mp[t[i]]) {
				int y = x | (1 << i);
				if (p[y] == -1) {
					p[y] = i;
					q.push(y);
				}
			}
		}
	}

	if (p[(1 << n) - 1] == -1) {
		puts("IMPOSSIBLE");
		return;
	}

	vector<int> a;

	int x = (1 << n) - 1;
	while(x) {
		a.push_back(p[x] + 1);
		x ^= 1 << p[x];
	}

	for(int i = (int)a.size() - 1; i >= 0; --i) {
		printf("%d%c", a[i], i ? ' ' : '\n');
	}

}

int main()
{
	freopen("D.in", "rt", stdin);

	bool submit = true;

	if (submit) {
		freopen("D.out", "wt", stdout);
	}

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		clear();
		readTest();
		printf("Case #%d: ", tt + 1);
		solveTest();
		if (submit) {
			cerr << "Case " << tt + 1 << " done\n";
		}
	}
	return 0;
}