#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll maximum(ll a, ll b)
{
	if (a > b)
		return a;
	else
		return b;
}
ll minimum(ll a, ll b)
{
	if (a < b)
		return a;
	else
		return b;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test_count = 0;
	cin >> test_count;
	for (int  test = 1; test <= test_count; test++)
	{
		int n,m;
		cin >> n >> m;
		vector < pair <ll, ll>> vn, vm;
		for (int i = 0 ; i < n; i++)
		{
			ll a, A;
			cin >> a >> A;
			vn.push_back(make_pair(a,A));
		}
		for (int i = 0 ; i < m; i++)
		{
			ll b, B;
			cin >> b >> B;
			vm.push_back(make_pair(b,B));
		}
		n = vn.size();
		m = vm.size();
		ll ans = 0;
		ll size = vn.size();
		for (int i = 0 ; i < m ; i++)
			for (int j = i ; j < m ; j++)
			{
				ll buf = 0 , sum = 0;
				vector < pair<ll ,ll >> vbuf = vm;
				for (int k = 0 ; k <= i; k++)
					if (vn[0].second == vbuf[k].second)
					{
						if (vn[0].first < sum + vbuf[k].first)
						{							
							vbuf[k].first = vbuf[k].first - (vn[0].first - sum);
							sum = vn[0].first;
						}
						else
						{
							sum += vbuf[k].first;
							vbuf[k].first = 0;													
						}
					}
				buf += minimum(sum, vn[0].first);
				ans = maximum(buf, ans);
				if (size < 2)
					continue;
				sum = 0;
				for (int k = i; k <= j; k++)
					if (vn[1].second == vbuf[k].second)
					{
						if (vn[1].first < sum + vbuf[k].first)
						{
							vbuf[k].first = vbuf[k].first - (vn[1].first - sum);
							sum = vn[1].first;
						}
						else
						{
							sum += vbuf[k].first;
							vbuf[k].first = 0;													
						}
					}
				buf += minimum(sum, vn[1].first);
				ans = maximum(buf, ans);
				if (size < 3)
					continue;
				sum = 0;
				for (int k = j; k < m; k++)
					if (vn[2].second == vbuf[k].second)
					{
						if (vn[2].first < sum + vbuf[k].first)
						{
							vbuf[k].first = vbuf[k].first - (vn[2].first - sum);
							sum = vn[2].first;
						}
						else
						{
							sum += vbuf[k].first;
							vbuf[k].first = 0;													
						}
					}
				buf += minimum(sum, vn[2].first);
				ans = maximum(buf, ans);
			}
			cout << "Case #" << test << ": " << ans << '\n';
	}
	return 0;
}