#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

set <int> visit;

ll reverse(ll x)
{
	//cout << x << endl;
	string s = "";
	while (x)
		s += (char)((x % 10) + '0'), x /= 10;

	ll p = 1, res = 0;
	for (int i = s.size()-1; i >= 0; i--)
		res += (s[i]-'0')*p, p *= 10;

	//cout << res << endl;
	return res;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		ll n;
		scanf("%lld", &n);
		visit.clear();

		ll ans = 0;
		queue <ii> cola;
		cola.push(MP(1, 1));
		visit.insert(1);
		while (!cola.empty())
		{
			ll s = cola.front().second;
			ll d = cola.front().first;
			cola.pop();

			if (s == n)
			{
				ans = d;
				break;
			}

			ll r = reverse(s);
			if (r <= n and r > s and visit.insert(r).second)
				cola.push(MP(d+1, r));
			if (visit.insert(s+1).second)
				cola.push(MP(d+1, s+1));
		}

		printf("Case #%d: %lld\n", caso++, ans);
	}

	return 0;
}