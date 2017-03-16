#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct chest {
	int key;
	vector < int > keys;

	void read() {
		cin >> key;
		int m;
		cin >> m;
		keys.resize(m);
		for (int i = 0; i < m; ++i) {
			cin >> keys[i];
		}
	}
};

vector < chest > a;
int k, n;
int d[1 << 20];
map < int, int > keys;

int calc(int opened) {
	if (d[opened] != -1) {
		return d[opened];
	}
	if (opened == 0) {
		return d[opened] = 1;
	}

	map < int, int > current = keys;
	for (int i = 0; i < n; ++i) {
		if (opened & (1 << i)) {
			--current[a[i].key];
			for (int j = 0; j < a[i].keys.size(); ++j) {
				++current[a[i].keys[j]];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if ((opened & (1 << i)) == 0) {
			continue;
		}

		if (calc(opened ^ (1 << i)) == 0) {
			continue;
		}

		++current[a[i].key];
		for (int j = 0; j < a[i].keys.size(); ++j) {
			--current[a[i].keys[j]];
		}

		if (current[a[i].key] > 0) {
			return d[opened] = 1;
		}

		--current[a[i].key];
		for (int j = 0; j < a[i].keys.size(); ++j) {
			++current[a[i].keys[j]];
		}
	}
	return d[opened] = 0;
}

bool solve(map < int, int > keys, int left) {
	//memset(d, -1, sizeof(d));
	int mask = left;
	while (true) {
		d[mask] = -1;
		if (mask == 0) {
			break;
		}
		mask = ((mask - 1) & left);
	}

	::keys = keys;
	return calc(left);
}

void solve(int test) {
	keys.clear();

	cin >> k >> n;
	for (int i = 0; i < k; ++i) {
		int key;
		cin >> key;
		++keys[key];
	}
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i].read();
	}
	
	memset(d, -1, sizeof(d));
	int res = calc((1 << n) - 1);
	if (res == 0) {
		printf("Case #%d: IMPOSSIBLE\n", test);
		return ;
	}

	int mask = (1 << n) - 1;
	printf("Case #%d:", test);
	vector < int > order;
	for (int step = 0; step < n; ++step) {
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				map < int, int > old = keys;
				map < int, int > current = keys;
				if (current[a[i].key] <= 0) {
					continue;
				}
				--current[a[i].key];
				for (int j = 0; j < a[i].keys.size(); ++j) {
					++current[a[i].keys[j]];
				}
				if (solve(current, mask ^ (1 << i))) {
					printf(" %d", i + 1);
					order.push_back(i + 1);
					mask ^= (1 << i);
					keys = current;
					break;
				} else {
					keys = old;
				}
			}
		}
	}
	if (mask != 0) {
		cerr << "BAD" << endl;
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		cerr << i << endl;
	}
	return 0;
}