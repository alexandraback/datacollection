#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int T;
set<int> s[2000001];

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	for (int i = 1; i <= 2000000; i++) {
		int l = 1, p = 1;
		while (l <= i) l *= 10;
		for (int j = 10; j <= i; j *= 10) {
			int k = i / j + (i % j) * (l / j);
			if (k > i) s[i].insert(k);
		}
	}

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int a, b, ans = 0;
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) {
			for (set<int> :: iterator k = s[j].begin(); k != s[j].end(); k++) {
				if (*k >= a && *k <= b) ans++;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
}
