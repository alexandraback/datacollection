#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

ll flip(ll a) {
	ll b = 0;
	
	while(a) {
		b *= 10;
		b += a%10;
		a /= 10;
	}
	return b;
}

ll count101(ll w) {
	if(w == 1) return 1;
	if(w == 11) return 11;

	ll g = 1;
	while(g*g < w-2) g*= 10;
	
	ll v = (w-10)/g;
	ll ans = 0;
	v *= g;
	v++;
	ans += w-v;
	ans++;
	v = flip(v);
	
	ll a = 1;
	while(a < v) a*= 10;
	a/=10;
	a++;
	ans += v-a;
	return ans + count101(a);
}

ll solve(ll N) {
	if(N <= 11) return N;
	ll n = N;
	ll ans = 0;
	if(n%10 == 0) {
		n--;
		ans++;
	}
	ll w = 1;
	while(w <= n) w*=10;
	w /= 10;
	w++;
	
	ans += count101(w);
	
	ll g = 1;
	while(g*g < w) g*=10;
	
	ll top = flip(n/g);
	if(top != 1) {
		ans += top-1;
		ans++;
	}
	ll bottom = n%g;
	ans += bottom-1;
	
	return ans;
}

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int tt = 1; tt <= T; tt++) {
		printf("Case #%d: ", tt);
		ll N;
		scanf("%lld", &N);
		
		printf("%lld\n", min(solve(N), N));
	}
	
	return 0;
}
