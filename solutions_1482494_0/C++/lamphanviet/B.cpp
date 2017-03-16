//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1111

int n;
ii a[maxN];
pair<bool, bool> flag[maxN];

bool cmp(ii x, ii y) { return x.ss > y.ss; }

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("B-small-attempt5.in", "r", stdin);
	//freopen("B-small-attempt5.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i].ff, &a[i].ss);
			flag[i].ff = flag[i].ss = true;
		}
		sort(a, a + n, cmp);
		int res = 0, stars = 0, atmp = 0;
		while (true) {
			bool take = false;
			// try all 2 stars
			for (int i = 0; i < n; i++)
				if (flag[i].ss && (stars >= a[i].ss)) {
					if (!flag[i].ff) stars += 1;
					else stars += 2;
					flag[i].ss = flag[i].ff = false;
					take = true;
					res++;
				}
			if (take) continue;
			// can't take 2 stars, try 1 star
			take = false;
			for (int i = 0; i < n; i++)
				if (flag[i].ff && flag[i].ss && (stars >= a[i].ff)) {
					stars += 1;
					flag[i].ff = false;
					take = true;
					res++;
					break;
				}
			if (!take) atmp++;
			if (atmp == 5) break;
		}
		if (stars != n * 2) res = INF;
		printf("Case #%d: ", ++caseNo);
		if (res == INF) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet