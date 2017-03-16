#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
#define ll long long 

using namespace std;


vector < pair < ll, ll > > a, b, c;
vector < int > w, h;
int t, n, m;
ll x, y;
ll ans;


inline bool bit(int k, int x)
{
	return ((k & (1 << x)) ? 1 : 0);
}


inline ll calc()
{
	ll ans = 0;
	ll r, tec;
	c = b;
	
	for (int i = 0; i < w.size(); i++)
	{
		tec = a[w[i]].first;
		
		for (int j = h[i]; j <= (i == w.size() - 1 ? m - 1 : h[i + 1]); j++)
		{
			if (a[w[i]].second == c[j].second)
			{
				r = min(tec, c[j].first);
				ans += r;
				c[j].first -= r;
				tec -= r;
			}
		}
	}
	
	//~ for (int i = 0; i < w.size(); i++)
		//~ cout << h[i] << ' ';
	//~ cout << ": " << ans << endl;
	
	return ans;
}

void rec(int sz, int beg)
{	
	if (sz == w.size())
	{
		ans = max(ans, calc());
		return;
	}
	
	for (int i = beg; i < m; i++)
	{
		h.push_back(i);
		rec(sz + 1, i);
		h.pop_back();
	}
}


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	for (int z = 0; z < t; z++)
	{
		cin >> n >> m;
		
		a.clear();
		b.clear();
		
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			b.push_back(make_pair(x, y));
		}
		
		ans = 0;
		
		cout << "Case #" << z + 1 << ": ";
		
		for (int k = 0; k < (1 << n); k++)
		{
			w.clear();
			
			for (int e = 0; e < n; e++)
				if (bit(k, e))
					w.push_back(e);
				
			h.clear();	
			rec(0, 0);
		}
		
		cout << ans << endl;
	}

	return 0;
}
