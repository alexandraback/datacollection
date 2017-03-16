#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef int typec;

typec r, t;

int main(void) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("me.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%d%d", &r, &t);
		typec sum = 0, rem = t;
		for (; ; r += 2) {
			rem -= 2 * r + 1;
			if (rem >= 0) sum++;
			else break;
		}
		printf("Case #%d: %d\n", T, sum);
	}
	return 0;
} 
