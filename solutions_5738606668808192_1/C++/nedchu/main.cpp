#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
bool a[105];
int res[105];
bool ck(int n, int mod, int b) {
	int rem = 0;
	for (int i = 0; i <= n+1; i++) {
		rem = rem * b % mod;
		if (a[i]) rem++;
	}
	return (rem % mod) == 0;
}

bool go(int n) {
	for (int i = 2; i <= 10; i++) {
		bool flag = false;
		for (int mod = i+1; mod <= 2000; mod++) {
			if (ck(n, mod, i)) {
				flag = true;
				res[i] = mod;
				break;
			}
		}
		if (!flag) return false;
	}
	for (int i = 0; i <= n+1; i++) {
		printf("%d", a[i]);
	}
	for (int i = 2; i <= 10; i++) {
		printf(" %d", res[i]);
	}
	puts("");
	return true;
}

int main() {
	int t, n, j, cas = 1;
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &j);
		printf("Case #%d:\n", cas++);
		n -= 2;
		int mx = 1 << n;
		a[0] = a[n+1] = true;
		for (int i = 0; i < mx; i++) {
			for (int j = 0; j < n; j++) {
				a[j+1] = (1 << j) & i;
			}
			if (go(n)) j--;
			if (!j) break;
		}
	}
	return 0;
}
