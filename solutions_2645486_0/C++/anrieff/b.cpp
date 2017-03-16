#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int n;
ll E, R;
ll w[10010];
ll maxe[10010], mine[10010];

ll solve(void)
{
	scanf("%lld%lld%d", &E, &R, &n);
	FOR(i, n) scanf("%lld", &w[i]);
	//
	vector<pair<ll, int> > v;
	FOR(i, n) v.push_back(make_pair(-w[i], i));
	stable_sort(v.begin(), v.end());
	//
	ll totalGain = 0;
	FOR(i, n) {
		maxe[i] = E;
		mine[i] = 0;
	}
	FOR(ii, n) {
		int i = v[ii].second;
		ll spend = (maxe[i] - mine[i]);
		totalGain += spend * w[i];
// 		printf("Spend %lld on %d\n", spend, i);
		for (int j = i + 1; j < n && mine[i] + (j - i) * R < E; j++)
			maxe[j] = min(maxe[j], mine[i] + (j - i) * R);
		for (int j = i - 1; j >= 0 && maxe[i] - (i - j) * R >= 0; j--)
			mine[j] = max(mine[j], maxe[i] - (i - j) * R);
	}
	//
	return totalGain;
}

int main(void)
{
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		printf("Case #%d: %lld\n", t, solve());
	}
	return 0;
}
