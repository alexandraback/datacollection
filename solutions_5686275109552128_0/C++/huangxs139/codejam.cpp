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
	int n;
	int w, cnt[1010];
	int cost;
	int ans;
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B-small-attempt3.out", "w", stdout);
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		ans = 1000;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &w);
			cnt[w]++;
		}
		for (int i = 1; i <= 1000; i++) {
			cost = 0;
			for (int j = i+1; j <= 1000; j++) {
				if (cnt[j])
					cost += cnt[j]*((j-1)/i);
			}
			ans = min(ans, cost+i);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
