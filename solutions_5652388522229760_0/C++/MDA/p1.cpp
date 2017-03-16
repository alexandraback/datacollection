#include "stdio.h"
#include <memory.h>

int solve(int n) {
	if (n == 0)
		return -1;
	int s[10];
	memset(s, 0, sizeof(s));
	int c = 0;
	int a = n;
	while (c < 10) {
		for (int z = a; z;) {
			int d = z % 10;
			z /= 10;
			if (!s[d]) {
				s[d] = 1;
				++c;
			}
		}
		a += n;
	}
	return a - n;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int start;
		scanf("%d", &start);
		printf("Case #%d: ", i+1);
		int last = solve(start);
		if (last == -1)
			printf("INSOMNIA\n");
		else
			printf("%d\n", last);
	}
}