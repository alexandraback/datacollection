#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include<fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define resetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define rd(x) scanf("%d", &x)
using namespace std;

#define oo 1e9

int n, m;

vector<vector<int> > g;

int table[1001];

int target;

int solve(int idx)
{
	if(idx == target)
		return 1;
	int &ret = table[idx];
	if(ret != -1)
		return ret;
	ret = 0;
	rep1(i, g[idx])
		ret += solve(g[idx][i]);
	return ret;
}

int main()
{


	freopen("input.in", "rt", stdin);
	freopen("output.in", "w", stdout);

	int cases;
	rd(cases);
	int inh;
	rep(c, cases)
	{
		g.clear();
		rd(n);
		g.resize(n);
		rep(i, n)
		{
			rd(m);
			rep(j, m)
			{
				rd(inh);
				--inh;
				g[i].push_back(inh);
			}
		}
		bool cool = false;
		rep(i, n)
		{
			memset(table, -1, sizeof table);
			target = i;
			rep(j, n)
			{
				if(i == j)
					continue;
				if(solve(j) >= 2)
				{
					cool = true;
					break;
				}
			}
			if(cool)
				break;
		}
		cout << "Case #" << c + 1 << ": " << (cool ? "Yes" : "No") << endl;
	}

	return 0;
}


