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
#define REP(i,n) for(int i=0; i<(n); i++)

int e, r, n;
int v[20];
int memo[10][20];

int calcula(int x, int ind) {
	if (ind == n) return 0;
	if (memo[x][ind] != -1) return memo[x][ind];
	int res = 0;
	for (int i = 0; i <= x; i++) {
		res = max(res, v[ind]*i + calcula(min(e, x-i+r), ind+1));
	}
	return memo[x][ind] = res;
}

int main()
{	
	int t;
	scanf("%d", &t);
	REP(k, t) {
		scanf("%d %d %d", &e, &r, &n);
		REP(i, n) scanf("%d", &v[i]);
		memset(memo, -1, sizeof(memo));
		int res = calcula(e, 0);
		printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}