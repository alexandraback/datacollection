#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define rep(i,n) for(i=0;i<(n);i++)
#define MAXN 100005

int A, B;
double p[MAXN], r[MAXN];

void solve() {
	int i;
	double res=1e100, cur;
	r[0] = 1;
	for(i=1;i<=A; i++) {
		r[i] = r[i-1] * p[i];
	}

	res = 2 + B;
	for(i=0;i<=A;i++) {
		cur = r[i] * (A-i + B-i + 1) + (1-r[i]) * (A-i+B-i+1 + B + 1);
		res = min(res, cur);
	}
	printf("%.12lf\n",res);

}

int main() {
	int T, kase=1;
	int i;
	scanf(" %d",&T);
	while(T--) {
		printf("Case #%d: ",kase++);
		scanf(" %d %d",&A, &B);
		for(i=1;i<=A;i++) scanf(" %lf", &p[i]);
		solve();
	}
	return 0;
}
