#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int b[2000010];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		int s[22];
		for (int j = 0; j < N; j++) {
			scanf("%d", &s[j]);
		}
		memset(b, -1, sizeof(b));
		int ans1 = -1;
		int ans2 = -1;
		for (int j = 1; j < (1<<20); j++) {
			int x = 0;
			for (int k = 0; k < N; k++) {
				if ((1<<k)&j)
					x += s[k];
			}
			if (b[x] >= 0) {
				ans1 = b[x];
				ans2 = j;
				break;
			}
			b[x] = j;
		}
		printf("Case #%d:\n", i+1);
		if (ans1 != -1) {
			const char *spc = "";
			for (int k = 0; k < N; k++) {
				if ((1<<k)&ans1) {
					printf("%s%d", spc, s[k]);
					spc = " ";
				}
			}
			printf("\n");
			spc = "";
			for (int k = 0; k < N; k++) {
				if ((1<<k)&ans2) {
					printf("%s%d", spc, s[k]);
					spc = " ";
				}
			}
			printf("\n");
		} else {
			printf("Impossible");
		}
	}
}
