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
#define maxN 100111

int n, m;
double p[maxN], mulp[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		mulp[0] = 1.0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &p[i]);
			mulp[i] = mulp[i - 1] * p[i];
		}
		
		double res = 1.0 + m + 1.0;
		for (int i = 0; i <= n; i++) {
			double pp = mulp[n - i];
			int x = i + i + (m - n) + 1;
			int y = x + m + 1;
			double tmpres = pp * x + (1.0 - pp) * y; 
			res = min(res, tmpres);
//			printf("%d: %lf\n", i, tmpres);
		}
		printf("Case #%d: %.12lf\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet