#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define CY 1000005

const char tb[] = "aeiou";

char str[CY];
int N;

bool can(int fro, int to) {
	int sum = 0, mx = 0;
	for (int i = fro; i <= to; ++i) {
		if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') sum++;
		else sum = 0;
		mx = max(mx, sum);
		if (mx >= N) return true;
	}
	return false;
}

int main(void) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%s%d", str, &N);
		int len = (int)strlen(str);
		int sum = 0;
		for (int k = N; k <= len; ++k) {
			for (int i = 0; i + k - 1 < len; ++i) {
				bool flag = can(i, i + k - 1);
				if (flag) sum++;
			}
		}
		printf("Case #%d: %d\n", T, sum);
	}
	return 0;
}
