#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x ) for( i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

//typedef long long i64;
typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1<<28);
const int MAX = 105;

i64 dp[MAX][MAX];
int n, m;

struct Pack {
	int tp;
	i64 amt;
} B[MAX], T[MAX];

i64 _max(i64 a, i64 b) {
	return a > b ? a : b;
}

i64 _min(i64 a, i64 b) {
	return a < b ? a : b;
}

i64 func(int pb, int pt, i64 pvb, i64 pvt) {
	int i, j, k;
	i64 ret = 0, tmp;
	i64 ab, at;

	if(dp[pb][pt] != -1) {
		return dp[pb][pt];
	}
	if(pb==n || pt==m) return 0;

	if(B[pb].tp != T[pt].tp) {
		ret = _max(func(pb+1, pt, pvb, pvt), func(pb, pt+1, pvb, pvt));
	}
	else {
		//if(pb==2 && pt==1) printf("aschi :P\n");
		if(pvb) {
			tmp = _min(pvb, T[pt].amt);
			ab = pvb - tmp;
			at = T[pt].amt - tmp;
		}
		else if(pvt) {
			tmp = _min(pvt, B[pb].amt);
			ab = B[pb].amt - tmp;
			at = pvt - tmp;
		}
		else {
			tmp = _min(T[pt].amt, B[pb].amt);
			ab = B[pb].amt - tmp;
			at = T[pt].amt - tmp;
		}

		if(ab == 0) {
			if(at == 0) {
				ret = _max(ret, _max(tmp + func(pb+1, pt+1, 0, 0), func(pb+1, pt+1, 0, 0)));
			}
			else {
				ret = _max(ret, _max(tmp + func(pb+1, pt, 0, at), func(pb+1, pt+1, 0, 0)));
			}
		}
		else if(at == 0) {
			if(ab == 0) {
				ret = _max(ret, _max(tmp + func(pb+1, pt+1, 0, 0), func(pb+1, pt+1, 0, 0)));
			}
			else {
				ret = _max(ret, _max(tmp + func(pb, pt+1, ab, 0), func(pb+1, pt+1, 0, 0)));
			}
		}
	}
	//printf("->%d %d %I64d %I64d -> %I64d\n", pb, pt, pvb, pvt, ret);
	return dp[pb][pt] = ret;
}

int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k;
	int test, t = 0, kase=0;
	i64 ans;

	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++) {
			scanf("%I64d %d", &B[i].amt, &B[i].tp);
		}
		for(i=0; i<m; i++) {
			scanf("%I64d %d", &T[i].amt, &T[i].tp);
		}
		memset(dp, -1, sizeof(dp));
		ans = func(0, 0, 0, 0);
		printf("Case #%d: %I64d\n", ++t, ans);
	}
	return 0;
}
