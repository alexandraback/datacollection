#include <cstdio>

using namespace std;

typedef long long int ll;

ll max(ll a, ll b) {
	return (a > b ? a : b);
}

ll min(ll a, ll b){
	return (a < b ? a : b);
}

int main(int argc, char const *argv[])
{
	freopen("iSC.in", "r", stdin);
	freopen("oSC.txt", "w", stdout);
	int tc, T, N;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		ll d1, d2, h1, h2, m1, m2, d, h, m;
		int ans = 0;
		if(N == 1) {
			scanf("%lld", &d);
			d1 = d2 = d;
			scanf("%lld", &h);
			h1 = h2 = h;
			scanf("%lld", &m);
			m1 = m; m2 = m + 1;
		}
		else {
			scanf("%lld%lld", &d1, &h1);
			scanf("%lld", &m1);
			scanf("%lld%lld", &d2, &h2);
			scanf("%lld", &m2);
		}
		ll c1 = (360 - d1) * m1;
		ll c2 = (360 - d2) * m2;
		if(max(c1, c2) > (360 * min(m1, m2))) ans = 1;
		else ans = 0;
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}