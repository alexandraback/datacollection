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

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		int t[120];
		int s = 0;
		int x = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &t[j]);
			if (t[j]%3 == 0) {
				if (t[j]/3 >= p)
					s++;
			} else {
				if (t[j]/3 + 1 >= p)
					s++;
			}
			if (t[j]%3 == 0 && t[j] >= 3) {
				if (p == t[j]/3+1) {
					x++;
				}
			} else if (t[j]%3 == 2 && t[j] <= 26) {
				if (p == (t[j]+4)/3) {
					x++;
				}
			}
		}
		x = min(x, S);
		printf("Case #%d: %d\n", i+1, s+x);
	}
}
