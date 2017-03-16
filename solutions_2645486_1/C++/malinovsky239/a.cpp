#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = int(1e4 + 5);

int have[N], after[N];
pair<int, int> v[N];

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		cerr << i << endl;
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);		

		for (int j = 0; j < n; j++) {
			scanf("%d", &v[j].first);
			v[j].second = j;
			have[j] = e;
			after[j] = 0;
		}
		sort(v, v + n);
		reverse(v, v + n);

		LL res = 0;

		for (int j = 0; j < n; j++) {
			res += LL(have[ v[j].second ] - after[ v[j].second ]) * v[j].first;
			int reserve = have[ v[j].second ];
			for (int k = v[j].second - 1; k >= 0; k--) {
				reserve -= r;
				if (reserve < 0)
					reserve = 0;
				after[k] = max(after[k], reserve);
			}

			int rest = after[v[j].second];
			for (int k = v[j].second + 1; k < n; k++) {
				rest += r;				
				if (rest > e) rest = e;
				have[k] = min(have[k], rest);
			}
		}
		printf("Case #%d: %I64d\n", i + 1, res);		
	}

	return 0;
}

