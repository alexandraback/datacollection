#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
int Mini(int x, int y) {
	return x < y ? x : y;
}
int Maxi(int x, int y) {
	return x > y ? x : y;
}
struct sg {
	int x;
	int y;
	bool friend operator < (const sg i, const sg j) {
		return i.x < j.x;
	}
}v[101];
int T, Co, i, j, k, l,N,le,ri;
char S[1505] , Print[3005];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		Co++;
		printf("Case #%d: ", Co);
		scanf("\n%s", S + 1);
		N = strlen(S + 1);
		le = ri = 1500; Print[le] = S[1];
		for (i = 2; i <= N; i++) {
			if (Print[le] > S[i]) {
				Print[++ri] = S[i];
			}
			else {
				Print[--le] = S[i];
			}
		}
		for (i = le; i <= ri; i++) {
			printf("%c", Print[i]);
		}
		printf("\n");
	}
	return 0;
}