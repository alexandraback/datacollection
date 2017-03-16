#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ll,ll> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll pow2[63];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("B-large (1).in", "r", stdin);
	freopen("GCJ20161C-2.out", "w", stdout);
	ll t; cin >> t;
	ll T = 0;
	pow2[0] = 1;
	for(ll i = 1; i < 63; i++)
	{
		pow2[i] = pow2[i - 1] * 2LL;
	}
	while(t--)
	{
		T++;
		cout << "Case #" << T << ": ";
		ll b; cin >> b;
		ll m; cin >> m;
		if(m > pow2[b - 2])
		{
			cout << "IMPOSSIBLE" << '\n';
		}
		else
		{
			cout << "POSSIBLE" << '\n';
			bool enable[51];
			for(ll i = 1; i <= 50; i++)
			{
				enable[i] = false;
			}
			if(m == pow2[b - 2])
			{
				for(ll i = 1; i <= b - 1; i++)
				{
					enable[i] = true;
				}
			}
			else
			{
				for(ll i = 2; i <= b - 1; i++)
				{
					if((pow2[i - 2] & m))
					{
						enable[i] = true;
					}
				}
			}
			for(ll i = 1; i <= b; i++)
			{
				for(ll j = 1; j <= b; j++)
				{
					if(i >= j) cout << 0;
					else
					{
						if(j < b) cout << 1;
						else
						{
							if(enable[i])
							{
								cout << 1;
							}
							else
							{
								cout << 0;
							}
						}
					}
				}
				cout << '\n';
			}
		}
	}
	return 0;
}
