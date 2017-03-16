#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 105

using namespace std;

char S[MAX];

int main() {
	int c, g, i, n, t;
	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf("%s", S);
		n = strlen(S);
		g = S[n - 1] == '+' ? 0 : 1;
		for (i = 1; i < n; i++)
			if (S[i] != S[i - 1])
				g++;
		printf("Case #%d: %d\n", c, g);
	}
	return 0;
}
