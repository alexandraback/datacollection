#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f

int n;
int v[30][2];

int memo[2000000];

bool complete(int mask) {
	for (int i = 0; i < n; i++) {
		if (! ( (1 << (2*i+1) & mask))) return false;
	}
	return true;	
}

int conta(int mask) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (((1 << (2*i) & mask))) {
			res = res + 1;
		}
		if (( (1 << (2*i+1) & mask))) {
			if (((1 << (2*i) & mask))) {
				res = res + 1;
			}
			else {
				res = res + 2;	
			}
		}
	}
	return res;
}

int calcula(int mask) {
	int stars = 0;
	if (complete(mask)) return 0;
	
	if (memo[mask] != -1) return memo[mask];
	
	stars = conta(mask);
	
	int res = INF;
	
	for (int i = 0; i < n; i++) {
		if (! ( (1 << (2*i) & mask))) {
			if (stars >= v[i][0]) {
				res = min(res, calcula(mask | (1 << (2 * i))) + 1);
			}
		}
		if (! ( (1 << (2*i+1) & mask))) {
			if (stars >= v[i][1]) {
				int x = calcula(mask | (1 << (2 * i + 1)));
				res = min(res, x + 1);
			}
		}
	}
	
	return memo[mask] = res;
}

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d", &n);
		for (int i = 0 ;i < n; i++) {
			scanf("%d %d", &v[i][0], &v[i][1]);	
		}
		memset(memo, -1, sizeof(memo));
		int res;
		res = calcula(0);
		if (res == INF) {
			printf("Case #%d: Too Bad\n", k+1);	
		}
		else
			printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}