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
	
char buf[1001];
char res[3000];

int main() {
#ifndef __GNUG__
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; ni(T);
	FF(tt, T) {
		printf("Case #%d: ", tt);
		scanf("%s", buf);
		int n = strlen(buf);
		int l = 1500; int r = 1500;
		char _M = 'A' - 1;
		F(i, n) {
			if (buf[i] >= _M) {
				res[l--] = buf[i];
				_M = buf[i];
			}
			else {
				res[++r] = buf[i];
			}
		}
		for (int i = l + 1; i <= r; i++) {
			printf("%c", res[i]);
		}
		puts("");
	}

	return 0;
}
