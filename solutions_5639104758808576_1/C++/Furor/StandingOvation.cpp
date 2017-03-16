#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 1005

using namespace std;

char str[MAX];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int a, c, cc, i, n, m;
	scanf("%d\n", &c);
	for (cc = 0; cc < c; cc++) {
		scanf("%d %s\n", &m, str);
		a = 0;
		n = 0;
		for (i = 0; i <= m; i++) {
			if (n < i) {
				a += (i - n);
				n = i;
			}
			n += str[i] - '0';
		}
		printf("Case #%d: %d\n", cc + 1, a);
	}
	return 0;
}

