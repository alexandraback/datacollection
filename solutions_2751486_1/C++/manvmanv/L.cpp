#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define CY 1000005
typedef long long LL;

char str[CY];
int N;

int main(void) {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%s%d", str, &N);
		int len = (int)strlen(str);
		LL sum = 0, pos = 0, rt = -1;
		for (int i = 0; i < len; ++i) {
			if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') pos++;
			else pos = 0;
			if (pos >= N) {
				rt = i;
				if (i + 1 - N + 1 >= 0) sum += i + 1 - N + 1;
			} else {
				if (rt + 1 - N + 1 >= 0) sum += rt + 1 - N + 1;
			}
		}
		printf("Case #%d: %lld\n", T, sum);
	}

	return 0;
}
