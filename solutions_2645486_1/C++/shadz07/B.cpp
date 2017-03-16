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

int n;
ll E, R, v[10005];

int main() {
	int T;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%lld %lld %d", &E, &R, &n);
		
		REP(i, n)
			scanf("%lld", &v[i]);
		
		ll maks = -1;
		
		// memset(flag, false, sizeof(flag));
		// memset(dist, 0, sizeof(dist));
		
		// FORD(i, n - 1, 0) {
			// if (maks < v[i]) {
				// maks = v[i];
				// flag[i] = true;
			// }
		// }
		
		ll energy = E;
		ll ans = 0;
		
		REP(i, n) {
			ll jarak = -1;
			
			FORU(j, i + 1, n - 1) {
				if (v[j] > v[i]) {
					jarak = j - i;
					break;
				}
			}
			
			if (jarak != -1) {
				ll energyTemp = energy + jarak * R;
				ll pakai = min(max((energyTemp - E), 0LL), energy);
				ans += pakai * v[i];
				energy -= pakai - R;
				
				// printf("%d %lld %lld\n", i, pakai, energy);
			}
			else {
				ans += energy * v[i];
				// printf("habis %d %lld\n", i, energy);
				energy = R;
			}
		}
		
		printf("Case #%d: %lld\n", tc, ans);
	}
	
	return 0;
}
