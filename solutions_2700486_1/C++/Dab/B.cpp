#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
const int MAXN = 4000;

int n, x, y;

double memo[MAXN][MAXN];

double f(int k, int n) {
	assert(k < MAXN);
	assert(n < MAXN);

	if(k == 0) return 1;
	if(n == 0) return 0;
	double res = memo[k][n];
	if(res >= 0) {
		return res;
	}
	return res = (f(k-1, n-1) + f(k, n-1))/2;
}

double solve() {
	int tmpx, tmpy;
	scanf("%d %d %d", &n, &tmpx, &tmpy);
	
	x = (tmpx+tmpy)/2;
	y = (tmpy-tmpx)/2;

	int nextLevel = 1;
	int i = -1;
	int size = 0;
	int len = -1;
	while(size + nextLevel <= n) {
		i++;
		size += nextLevel;
		nextLevel += 4;
		len+=2;
		if((x <= i && y == i) || (y <= i && x == i)) {
			return 1;
		}
	}

	i++;
	len+=2;

	int need = 0;
	if(x <= i && y == i) {
		need = len-(i-x);
	} else if(y <= i && x == i) {
		need = len-(i-y);
	} else {
		return 0;
	}
	if(need == len) {
		return 0;
	}

	int left = n-size;



	int minimum = max(0, left - (len-1));
	int maximum = min(len, left);

	if(need > maximum) {
		return 0;
	}
	if(need <= minimum) {
		return 1;
	}
	double res = 0;
	res = f(need, left);
	return res;
}

int main() {
	for(int i = 0; i < MAXN; i++) 
		for(int j = 0; j < MAXN; j++) 
			memo[i][j] = -1;
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %.9lf\n", i, solve());
	}
}