#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm> 
#include <cmath> 

#include <vector> 
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <sstream>


using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}


int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; ++t)
	{
		int n;
		cin >> n;
		vector <int> v(n);
		vector <int> g(n, 0);
		vector <int> used(n,0);
		vector <int> m(n,0);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			v[i]--;
			g[v[i]]++;
		}
		int res = n;
		for (int i = 0; i < n; ++i)
		{
			if (used[i])
				continue;
			int j = i;
			int c = 0;
			while (g[j] == 0)
			{
				res--;
				c = max(c, m[j]);
				m[j] = 0;
				c++;
				used[j] = 1;
				g[v[j]]--;
				j = v[j];
			}
			m[j] = max(m[j], c);
		}
		vector <int> good(n, 0);
		vector <pair <int, int> > gg(n);
		for (int i = 0; i < n; ++i)
		{
			gg[i] = make_pair(m[i], i);
			if (v[v[i]] == i)
			{
				good[i] = 1;
				good[v[i]] = 1;
			}
		}
		int len = 0;
		for (int i = 0; i < n; ++i)
		{
			if (good[i])
				len++;
		}
		res = 0;
		sort(gg.rbegin(), gg.rend());
		for (int i = 0; i < n; ++i)
		{
			if (good[gg[i].second])
			{
				good[gg[i].second] = 0;
				len += gg[i].first;
			}
			int c = 0;
			int j = i;
			while (!used[j])
			{
				c++;
				used[j] = 1;
				j = v[j];
			}
			res = max(c, res);
		}
		res = max(res, len);
		printf("Case #%d: %d\n",t + 1,res);	
	}
	return 0;
}