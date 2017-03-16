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
lld mic[25][25];
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
		for (int j = 1 ; j <= n ; j ++) {
			int i = j - 1;
			for (int k = 0 ; k <= e ; k ++) {
				mic[j][k] = 0;
				int tmp = max(k - r, (lld)0);
				for (int x = tmp ; x <= e ; x ++) {
					mic[j][k] = max(mic[j - 1][x] + val[i] * (x - tmp), mic[j][k]);
				}
			}
		}
		//for (int i = 0 ; i <= e ; i ++) {
		//	mic[n][0] = max(mic[n][0], mic[n][i] + val[n - 1] * i);
		//}
		printf("Case #%d: ", test + 1);
		printf("%lld\n", mic[n][0]);
	}
	return 0;
}