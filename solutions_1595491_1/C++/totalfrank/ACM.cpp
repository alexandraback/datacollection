#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool check(int s, int diff, int p) {
	for(int i = 0; i <= 10; ++i)
		for(int j = i; j <= i + diff && j <= 10; ++j)
			for(int k = j; k <= i + diff && k <= 10; ++k)
				if(i + j + k == s && k >= p) return true;
	return false;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int n, s, p, res = 0;
		scanf("%d%d%d", &n, &s, &p);
		for(int i = 0; i < n; ++i) {
			int u;
			scanf("%d", &u);
			if(check(u, 1, p)) ++res;
			else if(s && check(u, 2, p)) {
				++res;
				--s;
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
