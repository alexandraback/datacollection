#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef LL typec;

typec r, t;

int main(void) {
	freopen("A-large.in", "r", stdin);
	freopen("m2.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%lld%lld", &r, &t);
	//	cout << r << " " << t << endl; 
		typec lt = 0, rt = (typec)sqrt(1. * (t / 2)), mid;
		while(lt <= rt) {
			mid = lt + (rt - lt) / 2;
			if (mid == 0) lt = -~mid;
			if (mid && (t - 2 * mid * mid) / mid < (2 * r - 1)) rt = ~-mid;
			else lt = -~mid;
		}
		typec sum = rt;
		printf("Case #%d: %d\n", T, sum);
	}
	return 0;
} 
