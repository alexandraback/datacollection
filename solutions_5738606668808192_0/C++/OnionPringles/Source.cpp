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

ll get(int base, int bin) {
	ll res = 0;
	ll cur = 1;
	F(i, 16) {
		if (bin & (1 << i)) res += cur;
		cur *= base;
	}
	return res;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; ni(T);
	while (T--) {
		static int casen = 0;
		printf("Case #%d:\n", ++casen);
		int n, j;
		nii(n, j);
		int m = n / 2 - 2;
		F(i, j) {
			int ii = (1 << (m + 1)) + i * 2 + 1;
			F(k, 2) {
				for (int j = m + 1; j >= 0; j--) {
					printf("%d", !!(ii&(1 << j)));
				}
			}
			printf(" ");
			F(k, 9) {
				printf("%I64d ", get(k + 2, ii));
			}
			puts("");
		}
	}
	return 0;
}
