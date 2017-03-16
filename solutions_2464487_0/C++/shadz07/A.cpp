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

#define MAKS 2000000000000000000

int main() {
	int T;
	ll r, t;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%lld %lld", &r, &t);
		ll ans = 0;
		
		ll tambah = (2LL * r) + 1LL;
			
		while (t >= tambah) {
			t -= tambah;
			tambah += 4LL;
			++ans;
		}
		
		printf("Case #%d: %lld\n", tc, ans);
	}
	
	return 0;
}
