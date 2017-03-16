#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#define MAX 1005

using namespace std;

int P[MAX];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int a, c, cc, i, j, n, s;
	scanf("%d", &c);
	for (cc = 0; cc < c; cc++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &P[i]);
		sort(P, P + n);
		a = MAX;
		for (i = 1; i < MAX; i++) {
			s = 0;
			for (j = 0; j < n; j++)
				s += (P[j] - 1) / i;
			a = min(a, s + i);
		}
		printf("Case #%d: %d\n", cc + 1, a);
	}
	return 0;
}


