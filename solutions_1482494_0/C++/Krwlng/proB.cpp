#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define N 1010
int a[N], b[N], lev[N];
int n;

void conduct() {
	int i, j, ans, hold ,rest;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
	memset(lev, 0, sizeof(lev)); rest = n; hold = ans = 0;
	while (rest) {
		for (i = 0, j = -1; i < n; ++i) {
			if (lev[i] == 2) continue;
			if (hold >= b[i]) { j = i; break; }
			if (!lev[i] && hold >= a[i]) if (j < 0 || b[j] < b[i]) j = i;
		} if (i < n) { hold += 2-lev[j]; rest--; lev[j] = 2; }
		else if (j >= 0) { hold++; lev[j] = 1; }
		else { printf("Too Bad\n"); return; }
		ans++;
	} printf("%d\n", ans);
}

int main() {
	int time;
	scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	} return 0;
}
