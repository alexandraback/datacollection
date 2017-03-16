#include <stdio.h>

int main() {
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "wt", stdout);
	
	int res;
	int t;
	int n, s, p, d;
	int i, j;

	scanf("%d", &t);
	for(i = 1; i <= t; ++i) {
		res = 0;
		scanf("%d%d%d", &n, &s, &p);
		for(j = 0; j < n; ++j) {
			scanf("%d", &d);
			if((p * 3 - 2 < p ? p : p * 3 - 2) <= d)
				++res;
			else if(s > 0 && (p * 3 - 4 < p ? p : p * 3 - 4)  <= d) {
				++res;
				--s;
			}
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}