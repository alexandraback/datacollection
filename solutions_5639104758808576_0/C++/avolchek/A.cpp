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
		int n;
		scanf("%d ", &n);
		
		vector < int > a;
		for (int i = 0; i < n + 1; i++)
		{
			char c;
			scanf("%c", &c);
			for (int j = 0; j < c - '0'; j++)
				a.pb(i);
		}
		scanf("\n");
		
		
		int ans = 0;
		int cnt = 0;
		
		for (int x : a)
		{
			while (cnt < x)
			{
				cnt++;
				ans++;
			}
			cnt++;
		}
		
		printf("Case #%d: %d\n", tt, ans);		
	}

	
	return 0;
}



































