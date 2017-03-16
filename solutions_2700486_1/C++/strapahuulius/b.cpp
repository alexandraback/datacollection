// GCJ Round 1B 2013
// -- strapahuulius

// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}
int mem[64][64];
int mem_next = 0;
int look_up(int x, int y)
{
	if ((abs(x) + abs(y)) % 2)
		return 60;
	if (abs(x) + y > 6)
		return 60;
	assert(mem_next < 60);
	x += 32;
	y += 32;
	if (mem[x][y] != -1)
		return mem[x][y];
	return mem[x][y] = mem_next++;
}
map<LL, double> dp;
void update(int x, int y, LL state, double weight)
{
	int k = look_up(x, y);
	if (y == 0)
	{
		dp[state | (1LL << k)] += weight;
	}
	else
	{
		if (y >= 2)
		{
			int k = look_up(x, y - 2);
			if (!(state & (1LL << k)))
			{
				update(x, y - 2, state, weight);
				return;
			}
		}
		int k_left = look_up(x - 1, y - 1);
		int k_right = look_up(x + 1, y - 1);
		bool left_exists = (state & (1LL << k_left));
		bool right_exists = (state & (1LL << k_right));
		if (left_exists && right_exists)
		{
			dp[state | (1LL << k)] += weight;
		}
		else
		{
			double f = !left_exists && !right_exists ? 0.5 : 1.0;
			if (!left_exists)
			{
				update(x - 1, y - 1, state, weight * f);
			}
			if (!right_exists)
			{
				update(x + 1, y - 1, state, weight * f);
			}
		}
	}
}
double solve(int n, int x, int y)
{
	int layer = (abs(x) + y) / 2;
	int n_inner_layers = 0;
	for (int i=0; i<layer; i++)
		n_inner_layers += 4 * i + 1;
	if (n_inner_layers >= n)
		return 0.0;
	int n_outer_layers = n - n_inner_layers;
	if (n_outer_layers >= 4 * layer + 1)
		return 1.0;
	int pos = abs(x);
	if (pos == 0)
		return 0.0;
	int m = 2 * layer;
	pos = m - pos;
	if (n_outer_layers - (pos + 1) < 0)
		return 0.0;
	vector<vector<double> > dp(m + 2, vector<double>(m + 2, 0.0));
	dp[0][0] = 1.0;
	for (int sum=0; sum<=n_outer_layers; sum++)
		for (int i=0; i<=m && i<=sum; i++)
		{
			int j = sum - i;
			if (j > m)
				continue;
			if (i >= m && j >= m)
				continue;
			if (i == m)
			{
				dp[i][j + 1] += dp[i][j];
			}
			else if (j == m)
			{
				dp[i + 1][j] += dp[i][j];
			}
			else
			{
				dp[i + 1][j] += dp[i][j] * 0.5;
				dp[i][j + 1] += dp[i][j] * 0.5;
			}
		}
	long double res = 0.0;
	for (int i=pos+1; i<=n_outer_layers && i<=m; i++)
	{
		if (n_outer_layers - i >= 0 && n_outer_layers -i <= m)
			res += dp[i][n_outer_layers - (i)];
	}
	return res;
}
// code written during the competition follows
int main(int argc, char **argv)
{
	memset(mem, -1, sizeof mem);
	int kase;
	int n_read = scanf("%d\n", &kase);
	assert(n_read == 1);
	int kase_a = 0, kase_b = oo;
	if (argc > 1)
	{
		assert(argc == 3);
		int n_read = sscanf(argv[1], "%d", &kase_a);
		assert(n_read == 1);
		n_read = sscanf(argv[1], "%d", &kase_b);
		assert(n_read == 1);
		if (kase_a >= kase)
			return 0;
	}
	for (int tkase=0; tkase<kase; tkase++)
	{
		// read case
		int n, x, y;
		cin >> n >> x >> y;

		if (tkase < kase_a || tkase >= kase_b)
			continue;
		// process case
		/*
		dp.clear();
		dp[0] = 1.0;
		for (int i=0; i<n; i++)
		{
			vector<pair<long long, double> > next;
			FORIT(it, dp)
				if (__builtin_popcountll(it->first) == i)
				{
					next.push_back(*it);
				}
			FORIT(it, next)
			{
				update(0, 6, it->first, it->second);
			}
		}
		double res = 0.0;
		int k = look_up(x, y);
		FORIT(it, dp)
			if (__builtin_popcountll(it->first) == n && it->first & (1LL << k))
				res += it->second;
		*/
		printf("Case #%d: ", tkase+1);
		double res = solve(n, x, y);
		printf("%.7lf\n", res);
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
