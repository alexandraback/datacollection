#include <bits/stdc++.h>
using namespace std;
int T, k, c, s;
int main () {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small.attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", test);
		for (int i=1; i<=k; i++) printf(" %d", i);
		printf("\n");
	}
	return 0;
}
