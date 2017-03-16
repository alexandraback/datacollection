#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int s = 1; s <= T; s++)
	{
		printf("Case #%d: ", s);
		ll k, c, S;
		scanf("%lld%lld%lld", &k, &c, &S);
		if(c * S < k)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		for(ll i = 0; i < k; i += c)
		{
			ll ans = 0;
			for(ll j = i; j < i + c; j++) ans = ans * k + min(j, k - 1);
			printf("%lld ", ans + 1);
		}
		putchar('\n');
	}
	return 0;
}
