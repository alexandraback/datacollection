#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double lf;

vector<ll> good;
int digs[15];

inline bool palin(ll x)
{
	int sz = 0;
	for (; x; x /= 10) digs[sz++] = x % 10;
	for (int i = 0; i < sz / 2; i++) 
		if (digs[i] != digs[sz - i - 1])
			return false;
	return true;
}

inline void precalc()
{
	for (ll i = 1; i <= 10100000; i++)
		if (palin(i) && palin(i * i)) 
			cerr << i << " " << i * i << endl, 
			good.push_back(i * i);
}

inline int solve(ll a)
{
	return upper_bound(good.begin(), good.end(), a) - good.begin();
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d\n", &t);
	precalc();
	for (int i = 0; i < t; i++) 
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		cout << "Case #" << i + 1 << ": " << solve(b) - solve(a - 1) << endl;
	}
	return 0;
}
