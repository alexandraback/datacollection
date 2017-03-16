#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

#define PA pair<lld, lld>

#define MAX_N 100000

using namespace std;

typedef long long lld;

int tests;
lld maxx;
lld answer;
lld e,n,r;
lld val[MAX_N];
lld m[MAX_N];
lld l[MAX_N];
PA sv[MAX_N];
set<int> S;
set<int>::iterator it, it2;

int main() {
	scanf("%d", &tests);
	for (int test = 0 ; test < tests ; test ++) {
		scanf("%lld %lld %lld", &e, &r, &n);
		for (int i = 0 ; i < n ; i ++) {
			scanf("%lld", &val[i]);
			sv[i] = PA((int)val[i], i);
		}
		answer = 0;
		S.clear();
		sort(sv, sv + n);
		for (int i = n - 1 ; i >= 0 ; i --) {
			maxx = e;
			it = S.lower_bound(sv[i].second);
			if (it != S.begin()) {
				it2 = it;
				it2 --;
				maxx = min(maxx, l[*it2] + r * (sv[i].second - (*it2)));
			}
			m[sv[i].second] = maxx;
			if (it != S.end()) {
				lld tmpmaxx = min(maxx, maxx - (m[*it] - r * ((*it) - sv[i].second)));
				l[sv[i].second] = maxx - tmpmaxx;
				maxx = tmpmaxx;
			} else {
				l[sv[i].second] = 0;
			}
			answer += (maxx * sv[i].first);
			S.insert(sv[i].second);
			//printf("%lld %lld\n", maxx, sv[i].first);
		}
		printf("Case #%d: ", test + 1);
		printf("%lld\n", answer);
	}
	return 0;
}