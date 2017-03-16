#include <bits/stdc++.h>

#define TASK ""
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const ll INFLL = numeric_limits<long long>::max();
const ll INFINT = numeric_limits<int>::max();
const ld EPS = 1e-7;
const ll MOD = 1e9 + 7LL;
const ll MAXN = 250000;

int run()
{
	ll t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		ll n;
		cin >> n;
		map<ll, ll> mp;
		for (int i = 1; i < 2 * n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ll val;
				cin >> val;
				if (mp.find(val) != mp.end())mp[val]++;
				else mp[val] = 1;
			}
		}
		vector<ll> ans;
		for (auto i : mp)
		{
			if (i.second % 2 != 0)ans.push_back(i.first);
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << q + 1 << ": ";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef LOCAL
#ifdef STRESS
	freopen("input.txt","w",stdout);



#endif
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if(strcmp(TASK,"")!=0)
	{
		freopen(TASK".in", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}
#endif

	run();

	return 0;
}