#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll p2[41];

ll gcd(ll a, ll b)
{
	if (a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

int solve2(ll a, ll b, int gcnt)
{
	if (a>=b)
		return gcnt;
	
	return solve2(a, b/2, gcnt+1);
}

int solve(ll a, ll b)
{
	ll g = gcd(a, b);
	a /= g;
	b /= g;

	if (std::find(p2, p2+41, b) == p2+41)
		return -1;
	
	return solve2(a, b, 0);
}

int main()
{
	p2[0] = 1;
	for (int i=1; i<=40; ++i)
		p2[i] = p2[i-1] * 2;
	
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; ++i)
	{
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		int ans = solve(a, b);
		printf("Case #%d: ", i);
		if (ans < 0)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}
	
	return 0;
}