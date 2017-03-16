#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

int solve1(const vector < int > &a)
{
	auto check = [&](int u)
	{
		multiset < int > s;
		for (int x : a)
		{
			s.insert(x);
		}
			
		while (true)
		{
			int v = *s.rbegin();
			if (v <= u)
				return true;
			if (u == 0)
				return false;
			s.erase(s.find(v));
			s.insert(v / 2);
			s.insert(v - (v / 2));
			u--;
		}
	};
	
	int lo = 0, hi = 1234;
	while (hi - lo > 1)
	{
		int mid = (lo + hi) >> 1;
		
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	
	return hi;
}

int solve2(const vector < int > &a)
{
	int ans = 12345678;
	
	for (int i = 1; i <= 1005; i++)
	{
		int add = 0;
		
		for (int x : a)
		{
			int y = x / i;
			if (x % i)
				y++;
			y--;
			add += y;
		}
		
		ans = min(ans, i + add);
	}
	
	return ans;
}


int main()
{
	//srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	scanf("%d\n", &t);
	
	for (int tt = 1; tt <= t; tt++)
	{
		vector < int > a;
		
		int n;
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a.pb(x);
		}
		
		
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		
		//cerr << solve1(a) << " " << solve2(a) << endl;
		printf("Case #%d: %d\n", tt, solve2(a));		
	}

	
	return 0;
}




































