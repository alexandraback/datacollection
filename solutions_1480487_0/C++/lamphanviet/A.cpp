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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define eps 1e-9
#define maxN 222

int n, judge[maxN], sum;
double res[maxN];

bool ok(double p, int u) {
	double pp = 1.0 - p;
	double score = judge[u] + p * sum;
	//printf("%d: %lf %lf\n", u, p, score);
	rep(i, n)
		if (i != u) {
			if (judge[i] >= score) continue;
			double add = (score - judge[i]) / (double)sum;
			//printf("%lf %lf\n", pp, add);
			if (pp >= add) pp -= add;
			else return true;
		}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		sum = 0;
		rep(i, n) {
			scanf("%d", &judge[i]);
			sum += judge[i];
		}
		rep(i, n) {
			res[i] = 1.0;
			double lo = 0.0, hi = 1.0;
			while (fabs(lo - hi) > eps) {
				double mid = (lo + hi) / 2.0;
				if (ok(mid, i)) {
					res[i] = mid;
					hi = mid;
				}
				else lo = mid;
			}
		}
		printf("Case #%d:", ++caseNo);
		rep(i, n) printf(" %.10lf", res[i] * 100.0);
		puts("");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet