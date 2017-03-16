#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int ll;

void przyp()
{
	ll a, b;
	scanf("%lld/%lld", &a, &b);
	ll g = __gcd(a, b);
	a /= g;
	b /= g;
	if(__builtin_popcountll(b) != 1)
	{
		printf("impossible\n");
		return;
	}
	int wyn = 0;
	while(a < b)
	{
		a *= 2;
		wyn++;
	}
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		przyp();
	}
	return 0;
}
