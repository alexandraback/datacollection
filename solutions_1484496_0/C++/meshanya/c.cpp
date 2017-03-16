#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "c"
using namespace std;

const int N = 20;
const int S = N * 100000;
vector<int> ans[S + 1];
int a[N], n, t, sum;

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < S; ++i)
			ans[i].clear();
		for (int i = 1; i < (1 << n); ++i) {
			sum = 0;
			for (int j = 0; j < n; ++j)
				if (i & (1 << j))
					sum += a[j];
			ans[sum].pb(i);
		}
		printf("Case #%d:\n", it + 1);
		bool ok = false;
		for (int s = 0; !ok && (s < S); ++s)
			for (int i = 0; i < sz(ans[s]); ++i)
				for (int j = i + 1; j < sz(ans[s]); ++j)
					if ((ans[s][i] & ans[s][j]) == 0) {
						for (int k = 0; k < n; ++k)
							if (ans[s][i] & (1 << k))
								printf("%d ", a[k]);
						printf("\n");
						for (int k = 0; k < n; ++k)
							if (ans[s][j] & (1 << k))
								printf("%d ", a[k]);
						printf("\n");
						i = j = 1e9;
						ok = true;
					}
		if (!ok) printf("Impossible\n");
		fprintf(stderr, "%d\n", it);
	}
	return 0;
}