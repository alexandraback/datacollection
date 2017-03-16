#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openfiles()
{
#ifndef ONLINE_JUDGE
	freopen("test.in","rt",stdin);
	freopen("test.out","wt",stdout);
#endif
}

void solve(int test)
{
	int N, S, p, t[105];
	scanf("%d %d %d", &N, &S, &p);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}
	
	int total = 0;
	for (int i = 0; i < N; i++) {
		int tt = t[i] / 3;
		if (t[i] % 3) tt++;
		if (tt >= p) total++;
		else if (tt + 1 == p && (t[i] % 3 == 2 || (t[i] && t[i] % 3 == 0)) && S > 0) { S--; total++; }
	}
	
	static int ntest = 0;
	printf("Case #%d: %d\n", ++ntest, total);
}

int main()
{
	openfiles();
	int n; scanf("%d ",&n); REP(i,n) solve(i + 1);
	
	return 0;
}