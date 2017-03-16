#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

bool isValid(ll x) {
	while (!(x & (1LL)))
		x >>= 1LL;
	
	return (x == 1);
}

int main() {
	int T;
	ll p, q;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		printf("Case #%d: ", tc);
		
		scanf("%lld/%lld", &p, &q);
		
		ll fpb = __gcd(p, q);
		p /= fpb;
		q /= fpb;
		
		if (isValid(q)) {
			int ans = 0;
			
			while (p < q) {
				q >>= 1LL;
				++ans;
			}
			
			printf("%d\n", ans);
		}
		else
			puts("impossible");
	}
}
