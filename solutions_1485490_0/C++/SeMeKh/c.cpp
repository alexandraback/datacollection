#include <iostream>
using namespace std;

#define FOR(i, x) for(int i = 0; i < (x); i++)
#define SZ(x) (int)x.size()

typedef int II;
typedef long long ll;
#define int ll
const int MAXM = 100 + 10;

struct pck
{
	int t;
	ll c;
	pck(){}
	pck(int t, ll c):t(t), c(c){}
} up[3], dn[MAXM];

II main() 
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		int n, m;
		cin >> n >> m;
		FOR(i, n)
		{
			ll t, c;
			cin >> c >> t;
			if(i && up[i - 1].t == t)
			{
				i--;
				up[i].c += c;
				n--;
			}
			else
				up[i] = pck(t, c);
		}
		FOR(i, m)
		{
			ll t, c;
			cin >> c >> t;
			dn[i] = pck(t, c);
		}

		for(; n < 3; n++)
			up[n] = pck(200 + n, 0LL);

		ll ans = 0;
		for(int i = 0; i <= m; i++)
			for(int j = i; j <= m; j++)
			{
				ll d[3] = {0, 0, 0};
				FOR(k, m)
				{
					ll v = (k >= i) + (k >= j);
					if(dn[k].t == up[v].t)
						d[v] += dn[k].c;
				}
				ll ss = 0;
				FOR(k, 3)
					ss += min(d[k], up[k].c);
				ans = max(ans, ss);
			}

		if(up[0].t == up[2].t)
		{
			ll ss = 0;
			FOR(k, m)
				if(up[0].t == dn[k].t)
					ss += dn[k].c;
			ss = min(ss, up[0].c + up[2].c);
			ans = max(ans, ss);
		}

		cout << "Case #" << T + 1 << ": ";
		cout << ans << endl;
	}
	return 0;
}
