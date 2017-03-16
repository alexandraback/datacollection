#include <stdio.h>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100], flag, n, x, y, lt[100], top;
map<int, int> mp;
map<int, int> :: iterator it;

void dfs(int now, int mask, int sum) {
	if(flag) return;
	if(now == n) {
		it = mp.find(sum);
		if(it != mp.end()) {
			flag = 1;
			x = it->second;
			y = mask;
		}
		else {
			mp.insert(make_pair(sum, mask));
		}
		return;
	}
	dfs(now + 1, mask, sum);
	if(flag) return;
	dfs(now + 1, mask | (1 << now), sum + a[now]);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);

		mp.clear();
		flag = 0;
		dfs(0, 0, 0);

		printf("Case #%d:\n", q);
		if(flag) {
			top = 0;
			for(int i=0; i<n; ++i) {
				if((1<<i) & x) lt[top++] = a[i];
			}
			for(int i=0; i<top; ++i) printf("%d%c", lt[i], (i==top-1)?'\n':' ');

			top = 0;
			for(int i=0; i<n; ++i) {
				if((1<<i) & y) lt[top++] = a[i];
			}
			for(int i=0; i<top; ++i) printf("%d%c", lt[i], (i==top-1)?'\n':' ');
		}
		else puts("Impossible");
	}
	return 0;
}

