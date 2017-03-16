#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
const ll INF = (ll)2e18;
const int N = 20;

struct Answer
{
	ll delta;
	ll a, b;
	Answer () : delta(), a(), b() {}
	Answer (ll _d, ll _a, ll _b) : delta(_d), a(_a), b(_b) {}
	bool operator < (const Answer &ans) const
	{
		if (delta != ans.delta)
			return delta < ans.delta;
		if (a != ans.a)
			return a < ans.a;
		return b < ans.b;
	}
};

Answer dp[N][2];

Answer fixedSolve(string a, string b)
{
	for (int i = 0; i <= (int)a.length(); i++)
		dp[i][0] = dp[i][1] = Answer(INF, INF, INF);
	dp[(int)a.length()][0] = Answer(0, 0, 0);
	ll pow10 = 1;
	for (int i = (int)a.length() - 1; i >= 0; i--)
	{
		for (int z = 0; z < 2; z++)
		{
			if (dp[i + 1][z].delta == INF)
				continue;
			for (int d1 = 0; d1 < 10; d1++)
				for (int d2 = 0; d2 < 10; d2++)
				{
					if (a[i] != '?' && a[i] != d1 + '0')
						continue;
					if (b[i] != '?' && b[i] != d2 + '0')
						continue;
					int c1 = d1;
					int c2 = d2;
					int nz = 0;
					if (c1 > c2 && z == 1)
						c1--;
					else if (c1 <= c2 && z == 1)
					{
						nz = 1;
						c1 += 9;
					}
					else if (c1 < c2 && z == 0)
					{
						c1 += 10;
						nz = 1;
					}
					ll curDigit = c1 - c2;
					Answer loc = Answer(curDigit * pow10 + dp[i + 1][z].delta, d1 * pow10 + dp[i + 1][z].a, d2 * pow10 + dp[i + 1][z].b);
					if (loc < dp[i][nz])
					{
						dp[i][nz] = loc;
					}
				}
		}
		pow10 *= 10;
	}
	return dp[0][0];
}

void solve(string a, string b)
{
	Answer a1 = fixedSolve(a, b);
	Answer a2 = fixedSolve(b, a);
	if (a1 < a2)
	{
		printf("%0*lld %0*lld\n", (int)a.length(), a1.a, (int)a.length(), a1.b);
	}
	else
	{
		printf("%0*lld %0*lld\n", (int)a.length(), a2.b, (int)a.length(), a2.a);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		string a, b;
		cin >> a >> b;
		printf("Case #%d: ", i + 1);
		solve(a, b);
	}
	return 0;
}
