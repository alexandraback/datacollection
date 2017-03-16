#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define	MAXE	10
#define	MAXN	20

int e, r, n;
int pd[MAXN][MAXE];
int t[MAXN];

using namespace std;

int solve(int ee, int l) {
	int i, ans;
	
	if(l == n) return 0;
	if(pd[l][ee] != -1) return pd[l][ee];

	ans = 0;
	for(i=0; i <= ee; i++) {
		ans = max(ans,solve(min(e,ee-i+r),l+1)+t[l]*i);
	}

	pd[l][ee] = ans;
	return ans;
}

int main (void) {
	int i, j, k, d;

	scanf("%d", &d);
	for(k=1; k <= d; k++) {
		for(i=0; i < MAXN; i++)
			for(j=0; j < MAXE; j++)
				pd[i][j] = -1;

		scanf("%d %d %d", &e, &r, &n);	
		for(i=0; i < n; i++) scanf("%d", &t[i]);		
		printf("Case #%d: %d\n", k, solve(e,0));
	}
	return 0;
}
