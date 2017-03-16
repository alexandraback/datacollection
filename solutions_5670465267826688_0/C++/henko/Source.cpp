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

int multTable[][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
map <char, int> ctiMap;
int mult(int l, int r)
{
	bool sign = (l * r > 0);
	r = abs(r); l = abs(l);
	return (sign ? 1 : -1) * (multTable[l - 1][r - 1]);
}


//#define ONLINE_JUDGE
int main() 
{
#ifndef ONLINE_JUDGE
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ctiMap['i'] = 2;
	ctiMap['j'] = 3;
	ctiMap['k'] = 4;
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int l, x;
		string s;
		bool yes = false;
		cin >> l >> x >> s;
		int multRes = 1;
		for (int j = 0; j < l * x; ++j)
		{
			int r = ctiMap[s[j % l]];
			multRes = mult(multRes, r);
		}
		if (multRes != -1) {
			printf("Case #%d: NO\n", i);
			continue;
		}
		int cur = 1;
		for (int j = 0; j < l * x - 2 && !yes; ++j)
		{
			int r = ctiMap[s[j % l]];
			cur = mult(cur, r);
			if (cur == 2) {
				yes = true;
			}
		}
		char *ans = (yes ? "YES" : "NO");

		printf("Case #%d: %s\n", i, ans);
	}

	return 0;
}