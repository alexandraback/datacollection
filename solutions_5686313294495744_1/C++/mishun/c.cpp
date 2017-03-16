#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>


int n, k;
std::vector< std::vector<int> > g;
std::vector<int> mt;
std::vector<bool> used;

bool try_kuhn(int v)
{
	if(used[v])
		return false;
	used[v] = true;

	for(size_t i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(mt[to] == -1 || try_kuhn (mt[to]))
		{
			mt[to] = v;
			return true;
		}
	}

	return false;
}

int edgeCover(const std::vector< std::pair<int, int> > edges, const int ls, const int rs)
{
	n = ls;
	k = rs;

	g.assign(ls, std::vector<int>());
	for(int i = 0; i < (int)edges.size(); i++)
		g[ edges[i].first ].push_back(edges[i].second);

	int res = ls + rs;

	mt.assign(k, -1);
	for(int v = 0; v < n; ++v)
	{
		used.assign(n, false);
		if(try_kuhn(v)) res--;
	}

	return res;

/*
	const int n = (int)edges.size();
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
				l[ edges[i].first ] = true;
				r[ edges[i].second ] = true;
			}
				
		bool ok = true;
		for(int i = 0; i < ls; i++)
			ok = ok && l[i];
		for(int i = 0; i < rs; i++)
			ok = ok && r[i];
				
		if(ok)
			res = std::min(res, sz);
	}

	return res;*/
}


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
	
	printf("%i", (int)p.size() - edgeCover(p, ls, rs));
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

