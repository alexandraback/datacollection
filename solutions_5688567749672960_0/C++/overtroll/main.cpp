#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cur = 1, s10 = 10;
int cn = 1;

ll gt(ll x)
{
	ll cx = x;
	ll sm = 0;
	ll cc = 1;
	for (int i = 0; i < cn / 2; i++)
	{
		ll v = cx % 10;
		cx /= 10;
		sm += v * cc;
		cc *= 10;
	}
	ll ad = 0;
	for (int i = cn / 2; i < cn; i++)
	{
		ll v = cx % 10;
		cx /= 10;
		ad = ad * 10 + v;
	}
	sm += ad;
	return min(x - cur, sm);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for (int tst = 0; tst < tests; tst++)
	{
		ll ans = 1;
		ll n;
		cin >> n;
		if (n % 10 == 0)
		{
			ans++;
			n--;
		}
		s10 = 10, cur = 1, cn = 1;
		while (s10 < n)
		{
			ans += gt(s10 - 1);
			ans++;
			s10 *= 10, cur *= 10, cn++;
		}
		ans += gt(n);
		cout << "Case #" << tst + 1 << ": " <<  ans << endl;
	}
}