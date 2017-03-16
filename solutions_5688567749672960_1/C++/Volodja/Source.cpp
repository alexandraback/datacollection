#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:133217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define pi acos(-1.0)

const int MOD = 1000000007;
const int INF = 1000000007;

long long dp[1000001];

long long rev(long long x)
{
	long long sol = 0;

	while (x > 0)
	{
		sol = sol * 10 + x % 10;
		x /= 10;
	}

	return sol;
}

set< pair<int, long long> > s;

int len(long long x)
{
	if (x < 10) return 1;
	return len(x / 10) + 1;
}

long long solve(long long n)
{
	if (n < 10) return n;
	if (n % 10 == 0) return solve(n - 1) + 1;
	
	long long temp = n;
	int l = len(n);
	FOR(i, 0, (l + 1) / 2) n /= 10;
	FOR(i, 0, (l + 1) / 2) n *= 10;
	++n;

	long long from = rev(n);
	if (from == n) from = n - 1;
	return solve(from) + 1 + temp - n;
}

void calc()
{
	s.clear();
	FOR(i, 2, 1000001)
	{
		dp[i] = INF;
		s.insert(MP(INF, i));
	}
	s.insert(MP(1, 1));
	dp[1] = 1;

	FOR(iter, 1, 1000000)
	{
		pair< int, long long > p = *s.begin();
		s.erase(s.begin());

		if (p.second + 1 <= 1000000 && dp[p.second + 1] > dp[p.second] + 1)
		{
			s.erase(s.find(MP(dp[p.second + 1], p.second + 1)));
			dp[p.second + 1] = dp[p.second] + 1;
			s.insert(MP(dp[p.second + 1], p.second + 1));
		}

		int r = rev(p.second);

		if (r <= 1000000 && dp[r] > dp[p.second] + 1)
		{
			s.erase(s.find(MP(dp[r], r)));
			dp[r] = dp[p.second] + 1;
			s.insert(MP(dp[r], r));
		}
	}
}

void test(int x)
{
	FOR(i, 1, x)
	{
		if (i%10000==0) cerr << i / 10000 << endl;
		if (dp[i] != solve(i))
		{
			cerr << "err " << i << " " << dp[i] << " " << solve(i) << endl;
		}
	}
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//calc();

	//test(1000001);
	//return 0;

	int t;
	cin >> t;

	FOR(T, 0, t)
	{
		long long n;
		cin >> n;
		cout << "Case #" << T + 1 << ": " << solve(n) << endl;
	}

	return 0;
}