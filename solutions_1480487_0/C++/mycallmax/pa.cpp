#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 2147483647 
#define MAX 2000
using namespace std;
int s[MAX], n, x;
int compute(int me, double y) {
	int i, xx = 0, nn = 0;
	double now = s[me] + x * y;
	for(i=0;i<n;i++) {
		if( i != me && s[i] < now) {
			xx += s[i];
			nn++;
		}
	}
	//printf("now=%lf, xx=%d, nn=%d, aa=%lf\n", now, xx, nn, (xx + x * (1 - y)));
	if( now * nn >= (xx + x * (1 - y))) return 1;
	else return 0;
}
int main() {
	int cases, i, j, k, T, ans;
	double y, left, right, mid;
	scanf("%d", &T);
	for(cases=0; cases < T; cases++) {
		scanf("%d", &n);
		x = 0;
		for(i=0;i<n;i++) {
			scanf("%d", &s[i]);
			x += s[i];
		}
		printf("Case #%d:", cases + 1);
		for(i=0;i<n;i++) {
			left = 0;
			right = 1.0;
			while( (right - left) >= 10e-13) {
				mid = (right + left) / 2;
				//printf("left=%lf, right=%lf, mid=%lf\n", left, right, mid);
				ans = compute(i, mid);
				if(ans == 0) left = mid;
				else right = mid;
			}
			printf(" %lf", mid*100);
		}
		printf("\n");
	}
	return 0;
}
