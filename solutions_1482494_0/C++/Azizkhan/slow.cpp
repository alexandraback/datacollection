#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std; 

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)

typedef pair <int, int> pi;

const int inf = int(1e9);
int a[1111], b[1111], n;
map <int, int> dp[2005][1111];

int calc(int p, int m1, int m2) {
	//printf("%d %d %d\n", p, m1, m2);
	if (m1 == (1 << n) - 1 && m2 == (1 << n) - 1)
		return 0;
	if (dp[p][m1].count(m2))
		return dp[p][m1][m2];
	int res = inf;	
	
	for (int i = 0; i < n; ++i) {
		if (!(m1 & (1 << i)) && p >= a[i]) {
			int cur = calc(p + 1, m1 | (1 << i), m2);
			res = min(res, cur + 1);
		}
		if (!(m2 & (1 << i)) && p >= b[i]) {
			int pp = p + 1;
			if (!(m1 & (1 << i))) ++pp;
			int cur = calc(pp, m1 | (1 << i), m2 | (1 << i));
			res = min(res, cur + 1);
		}
	}	
	dp[p][m1][m2] = res;
	return res;
}

int solve() {
	for (int i = 0; i < 2005; ++i)
		for (int mask = 0; mask < (1 << n); ++mask)
			dp[i][mask].clear();
	return calc(0, 0, 0);			
}

int main() {
	int tests;
	scanf("%d", &tests);
	for (int casenum = 1; casenum <= tests; ++casenum) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		int res = solve();
		printf("Case #%d: ", casenum);				
		if (res < inf)
			printf("%d\n", res);	
		else
			puts("Too Bad");						
	}
	return 0;		
}

