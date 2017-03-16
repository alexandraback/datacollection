#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
int const N = 10000;
llint e, r;
int n;
llint val[N];
vector <pair <llint, int> > activities;
bool readin()
{
	if (scanf("%I64d%I64d%d", &e, &r, &n) == EOF)
	{
		return false;
	}
	activities.clear();
	for (int i = 0, j; i < n; ++i)
	{
		scanf("%d", &j);
		val[i] = j;
		activities.push_back(make_pair(llint(j), i));
	}
	return true;
}
llint solve()
{
	llint ret = 0;
	set <pair <int, llint> > s;
	sort(activities.begin(), activities.end());
	for (vector <pair <llint, int> >::reverse_iterator it = activities.rbegin();
			it != activities.rend(); ++it)
	{
		pair <llint, int> const &a = *it;
		if (s.empty())
		{
			ret += e * a.first;
			s.insert(make_pair(a.second, 0LL));
		}
		else
		{
			set <pair <int, llint> >::iterator i_gt = s.lower_bound(make_pair(a.second, 0LL));
			set <pair <int, llint> >::iterator i_lt;
			if (i_gt == s.end())
			{
				i_lt = i_gt;
				--i_lt;
				llint u = min(i_lt -> second + r * (a.second - i_lt -> first), e);
				ret += u * a.first;
				s.insert(make_pair(a.second, 0LL));
			}
			else if (i_gt == s.begin())
			{
				llint u = min(r * (i_gt -> first - a.second), e);
				ret += u * a.first;
				s.insert(make_pair(a.second, e - u));
			}
			else
			{
				i_lt = i_gt;
				--i_lt;
				llint rem = min(i_lt -> second + r * (a.second - i_lt -> first), e);
				llint u = rem + r * (i_gt -> first - a.second) <= e ? 0 : min(rem, rem + r * (i_gt -> first - a.second) - e);
				ret += u * a.first;
				s.insert(make_pair(a.second, rem - u));
			}
		}
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int cc = 1; cc <= tc; ++cc)
	{
		readin();
		printf("Case #%d: %I64d\n", cc, solve());
	}
	return 0;
}
