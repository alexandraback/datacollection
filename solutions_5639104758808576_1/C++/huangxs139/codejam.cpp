//============================================================================
// Name        : codejam.cpp
// Author      : huangxs139
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int n, m;
	int ans;
	int w[1010];
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
			scanf("%1d", &w[i]);
		m = w[0];
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (m < i) {
				ans += (i-m);
				m = i;
			}
			m += w[i];
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
