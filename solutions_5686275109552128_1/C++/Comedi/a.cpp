#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;
int n, a[10005];

int check(int mx) {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		ret += (a[i] + mx - 1) / mx - 1;	
	}
	return ret + mx;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int ans = a[n - 1];
		for(int i = 1; i < a[n - 1]; i++) {
			int tmp = check(i);
			ans = min(ans, tmp);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
