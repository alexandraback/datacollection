#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }
template <typename T> T _min(T a, T b) { return a < b ? a : b; }
template <typename T> T _max(T a, T b) { return a > b ? a : b; }

using namespace std;

std::vector<LL> q;

bool sq(LL x)
{
	std::vector<int> v;
	v.clear();
	while (x)
	{
		v.push_back(x % 10);
		x /= 10;
	}
	int n = (int) v.size() - 1;
	for (int i = 0; i < n; i++, --n)
		if (v[i] != v[n])
			return false;
	return true;
}

int main()
{
//*
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
//*/
	for (LL i = 1; i <= 10000000; i++)
		if (sq(i) && sq(i * 1ll * i))
		{
			q.push_back(i * 1ll * i);
			// cout<< i<< " "<< i * i<< endl;
		}
	int t;
	cin>> t;
	for (int test = 1; test <= t; test++)
	{
		int ans = 0;
		LL l, r;
		cin>> l>> r;
		for (int j = 0; j < (int) q.size(); j++)
			ans += (q[j] >= l && q[j] <= r);
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
