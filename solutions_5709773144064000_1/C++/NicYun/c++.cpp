#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++) 

using namespace std;

const int N = 4;

int main() {
	freopen("D:/b-large.in", "r", stdin);
	freopen("D:/b-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	REP(t, T) {
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		double res = 1e20;
		double pre = 0;
		double per = 2.0;
		while(true) {
			double time = x / per;
			if (time + pre > res) break;
			res = time + pre;
			pre += c / per;
			per += f;
		}
		printf("Case #%d: %.7lf\n", t + 1, res);
	}
	return 0;
}