#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (10000+10)

int T, n, x;
int p[MAXN];
int f[MAXN][MAXN];

const int m[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int mul(int x, int y) {
	int k = m[abs(x)][abs(y)];
	if (x < 0) k *= -1;
	if (y < 0) k *= -1;

	return k;
}

int cal(int now, int goal, int mode) {
	if (now == goal) return 0;
	if (mode == 1) {
		for (int i = 0;i < n;++i){
			now = mul(now, p[i]);
			if (now == goal) return i+1;
		}
		return -1;
	}else {
		for (int i = n-1;i >= 0;--i){
			now = mul(p[i], now);
			if (now == goal) return n-i;
		}
		return -1;
	}
}

bool solve( int id ) {
	char c;
	int tot = 1;
	int now = 0, y;

	scanf("%d%d%*c",&n,&x);
	for (int i = 0;i < n;++i){
		scanf("%c", &c);
		if (c == 'i') p[i] = 2;
		else if (c == 'j') p[i] = 3;
		else if (c == 'k') p[i] = 4;
		tot = mul( tot, p[i] );
	}
//	printf("%d\n", tot);
	if (tot == 1) return false;
	if (tot == -1 && (x%2==0)) return false;
	if (tot != 1 && tot != -1 && (x%4!=2)) return false;

	y = cal(1, 2, 1);
//	printf("%d\n", y);
	if (y > 0) now += y;
	else {
	//	if (x <= 1) return false;
		--x;
		y = cal(tot, 2, 1);
		if (y >= 0) now += y;
		else {
	//		if (x <= 1) return false;
			--x;
			y = cal(mul(tot, tot), 2, 1);
			if (y >= 0) now += y;
			else {
				--x;
				y = cal(mul(mul(tot, tot),tot), 2, 1);
				if (y < 0) return false;
			
				now += y;
			}
		}
	}
//	printf("%d %d\n", now, x);
	if (x < 0) return false;
	y = cal(1, 4, -1);
//	printf("%d\n", y);
	if (y > 0) now += y;
	else {
	//	if (x <= 1) return false;
		--x;
		y = cal(tot, 4, -1);
	//	printf("%d\n", y);
		if (y >= 0) now += y;
		else {
		//	if (x <= 1) return false;
			--x;
			y = cal(mul(tot, tot), 4, -1);
			if (y >= 0)  now += y;
			else {
				--x;
				y = cal(mul(mul(tot, tot),tot), 4, -1);
				if (y < 0) return false;
				now += y;
			}
		}
	}
	if ((now-1)/n+1 <= x) return true;
	return false;
	
}

int main() {
	//printf("sdf");
	freopen("C-large.in", "r", stdin);
	//freopen("C.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	//printf("sdf");
	for (int i = 1;i <= T;++i){
		if (solve(i)) printf("Case #%d: YES\n", i);
		else printf("Case #%d: NO\n", i);
	}
	return 0;
}