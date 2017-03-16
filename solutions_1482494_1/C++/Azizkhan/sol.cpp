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

int color[1111], a[1111], b[1111];
int order[1111], n;

bool cmp(int i, int j) {
	return b[i] < b[j];
}

int solve() {
	for (int i = 0; i < n; ++i) {
		order[i] = i;
		color[i] = 0;
	}	
	sort(order, order + n, cmp);
	int res = 0, points = 0;
	
	int i = 0;
	while (i < n) {
		int j = order[i];
		if (color[j] != 2 && b[j] <= points) {
			points += 2 - color[j];
			color[j] = 2;
			++i;
			++res;
			continue;
		}
		int rp = -1;
		for (int k = 0; k < n; ++k) if (color[k] == 0 && a[k] <= points) {
			if (rp == -1 || b[rp] < b[k])
				rp = k;
		}
		if (rp == -1) return inf;
		
		color[rp] = 1;
		++res;
		++points;
	}
	if (i == n) return res;
	return inf;
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

