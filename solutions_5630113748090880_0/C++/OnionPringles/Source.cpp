#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x)
#define print(x) printf("%d ", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
	

int h[2501];

int main() {
#ifndef __GNUG__
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; ni(T);
	FF(tt, T) {
		printf("Case #%d: ", tt);
		memset(h, 0, sizeof(h));
		int n; ni(n);
		F(i, 2 * n - 1) {
			F(j, n) {
				int x; ni(x);
				h[x]++;
			}
		}
		vector<int> ans;
		F(i, 2501) {
			if (h[i] % 2 == 1) ans.push_back(i);
		}
		assert((int)ans.size() == n);
		sort(ans.begin(), ans.end());
		for (auto &x : ans) print(x);
		puts("");
	}
	return 0;
}
