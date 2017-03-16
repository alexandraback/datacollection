#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long lint;

#define MP make_pair
#define PB push_back
#define EPS 0.0000001
#define ALL(a) a.begin(), a.end()

const int INF = 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const lint INF_L = 1000 * 1000 * 1000;
const ll INF_LL = 1LL * INF_L * INF_L;
const ll MOD_LL = 1000000000007LL;


ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

int reverse(int n)
{
	string s = to_string(n);
	string s1 = "";
	for (int i = s.length() - 1; i >= 0; --i)
		s1 += s[i];
	return atoi(s1.c_str());
}


int dp[1000002];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	dp[1] = 1;
	for (int j = 1; j <= 1000000; ++j)
	{
		dp[j] = j;
	}
	for (int j = 2; j <= 1000000; ++j)
	{
		int rev = reverse(j);
		if (rev > j)
		{
			dp[rev] = min(dp[rev], dp[j] + 1);
		}
		dp[j + 1] = min(dp[j + 1], dp[j] + 1);
	}
	for (int i = 1; i <= t; ++i)
	{
		int n;
		cin >> n;
		printf("Case #%d: %d\n", i, dp[n]);
	}

	return 0;
}