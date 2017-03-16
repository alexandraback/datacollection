#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define	LL	long long int

#define	MAXN	200

int a, n, m[MAXN];
int pd[MAXN][1010];

int compare(const void *x, const void *y) {
	return *(int *)x - *(int *)y;
}

int solve(int idx, int sz) {
	int ans;
	if(idx == n) return 0;
	if(pd[idx][sz] != -1) return pd[idx][sz];

	if(sz > m[idx]) ans = solve(idx+1, sz+m[idx]);
	else {
		if(sz > 1) ans = min(solve(idx+1,sz)+1, solve(idx, sz+sz-1)+1);
		else ans = solve(idx+1,sz)+1;
	}	

	pd[idx][sz] = ans;
	return ans;
}


int main (void) {
	int i, j, k, t;
	LL tmp;

	scanf("%d", &t);
	for(k=1; k <= t; k++) {
		scanf("%d %d", &a, &n);
		for(i=0; i < n; i++) scanf("%d", &m[i]);
		qsort(m, n, sizeof(int), compare);
		tmp = a;
		for(i=0; i < n && tmp > m[i]; i++) tmp += m[i];
		if(i == n)  printf("Case #%d: 0\n", k);
		else {
			for(i=0; i < MAXN; i++)
				for(j=0; j < 1010; j++)
					pd[i][j] = -1;

			printf("Case #%d: %d\n", k, solve(0,a));
		}
	}

	return 0;
}
