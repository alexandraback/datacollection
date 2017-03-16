#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> v;

bool isPalindrome(ll x)
{
	char cc[64];
	sprintf(cc, "%I64d", x);
	int l = strlen(cc);
	int y = 0, z = l - 1;
	while (y < z)
	{
		if (cc[y] != cc[z])
		{
			return false;
		}
		++y; --z;
	}

	return true;
}

int main()
{
	for (int i = 1; i < 10000001; ++i)
	{
		ll x;
		if (isPalindrome(i) && isPalindrome(x = ll(i) * ll(i)))
		{
			v.push_back(x);
		}
	}

	int t, cases = 0;
	scanf("%d", &t);
	while (t--)
	{
		ll l, r;
		scanf("%I64d%I64d", &l, &r);
		int L = lower_bound(v.begin(), v.end(), l) - v.begin();
		int R = upper_bound(v.begin(), v.end(), r) - v.begin();
		printf("Case #%d: %d\n", ++cases, R - L);
	}
}