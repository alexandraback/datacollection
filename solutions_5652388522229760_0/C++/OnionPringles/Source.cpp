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

int chk[10];
int cnt = 0;

void f(int n) {
	while (n) {
		if (!chk[n % 10]) {
			chk[n % 10] = 1;
			cnt++;
		}
		n /= 10;
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; ni(T);
	while (T--) {
		static int casenum = 0;
		printf("Case #%d: ", ++casenum); 
		memset(chk, 0, sizeof(chk));
		cnt = 0;
		int n; ni(n);
		if (!n) {
			puts("INSOMNIA"); continue;
		}
		int m = n;
		while (1) {
			f(m); 
			if (cnt == 10) {
				println(m);
				break;
			}
			m += n;
			
		}
	}
	return 0;
}
