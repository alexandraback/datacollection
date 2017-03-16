#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>


int index(std::map< std::string, int > & m, const char * cs)
{
	std::string s = cs;
	int r = m.size();

	if(m[s] == 0)
	{
		m[s] = 1 + r;
		return r;
	}
	else
		return m[s] - 1;
}

void solve()
{
	int ls = 0, rs = 0;
	std::vector< std::pair<int, int> > p;

	{
		std::map< std::string, int > lm, rm;
		int n;
		scanf("%i\n", &n);
		
		char bufa[1024], bufb[1024];
		for(int i = 0; i < n; i++)
		{
			scanf("%s %s\n", bufa, bufb);
			int a = index(lm, bufa);
			int b = index(rm, bufb);

			p.push_back(std::make_pair(a, b));		
		}

		ls = (int)lm.size();
		rs = (int)rm.size();
	}

	{
		const int n = (int)p.size();

		int res = n;

		std::vector<bool> l(ls, false), r(rs, false);
		const int border = 1 << n;
		for(int mask = 1; mask < border; mask++)
		{
			for(int i = 0; i < ls; i++)
				l[i] = false;
			for(int i = 0; i < rs; i++)
				r[i] = false;

			int sz = 0;
			for(int i = 0; i < n; i++)
				if(mask & (1 << i))
				{
					sz++;
					l[ p[i].first ] = true;
					r[ p[i].second ] = true;
				}
				
			bool ok = true;
			for(int i = 0; i < ls; i++)
				ok = ok && l[i];
			for(int i = 0; i < rs; i++)
				ok = ok && r[i];
				
			if(ok)
				res = std::min(res, sz);
		}
		
		printf("%i", n - res);
	}
}

int main()
{
	int tests;
	scanf("%i\n", &tests);
	
	for(int test = 1; test <= tests; test++)
	{
		printf("Case #%i: ", test);
		solve();
		printf("\n");
	}

	return 0;
}

