#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define	LL	long long int

#define	MAXN	200

int a, n;
LL m[MAXN];
map<pair<int,LL>,int> pd;

int solve(int idx, LL sz) {
	int ans;
	if(idx == n) return 0;
	if(pd.count(make_pair(idx,sz))) return pd[make_pair(idx,sz)];

	if(sz > m[idx]) ans = solve(idx+1, sz+m[idx]);
	else {
		if(sz > 1) ans = min(solve(idx+1,sz)+1, solve(idx, sz+sz-1)+1);
		else ans = solve(idx+1,sz)+1;
	}	

	return pd[make_pair(idx,sz)] = ans;
}


int main (void) {
	int i, j, k, t;
	LL tmp;

	scanf("%d", &t);
	for(k=1; k <= t; k++) {
		scanf("%d %d", &a, &n);
		for(i=0; i < n; i++) cin >> m[i]; 
		sort(m,m+n);
		tmp = (LL)a;
		for(i=0; i < n && tmp > m[i]; i++) tmp += m[i];
		if(i == n)  printf("Case #%d: 0\n", k);
		else {
			pd.clear();
			printf("Case #%d: %d\n", k, solve(0,a));
		}
	}

	return 0;
}
