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

enum Q
{
	ONE,
	I,
	J,
	K
};

pair < int, Q > table[4][4] =
{
	mp(0, ONE), mp(0, I), mp(0, J), mp(0, K),
	mp(0, I), mp(1, ONE), mp(0, K), mp(1, J),
	mp(0, J), mp(1, K), mp(1, ONE), mp(0, I),
	mp(0, K), mp(0, J), mp(1, I), mp(1, ONE),
};

pair < int, Q > operator * (const pair < int, Q > &a, const pair < int, Q > &b)
{
	auto res = table[a.snd][b.snd];
	res.fst ^= a.fst;
	res.fst ^= b.fst;
	return res;
}

const int maxn = 100005;
const int maxk = 25;

char s[maxn * maxk];

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
		ll n, m;
		scanf("%lld %lld\n", &n, &m);
		
		ll k = max(0LL, m / 4 - 4);
		m -= 4LL * k;
		
		scanf("%s\n", s);
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				s[n * (i + 1) + j] = s[n * i + j];
				
		int step = 0;
		pair < int, Q > c(0, ONE);
		map < char, Q > ch2q({ mp('i', I), mp('j', J), mp('k', K) });
		
		for (int i = 0; i < n * m; i++)
		{
			c = c * mp(0, ch2q[s[i]]);
			
			if (step == 0 && c == mp(0, I))
			{
				step++;
				c = mp(0, ONE);
			}
			else if (step == 1 && c == mp(0, J))
			{
				step++;
				c = mp(0, ONE);
			}
			else if (step == 2 && c == mp(0, K) && i == n * m - 1)
			{
				step++;
			}
		}
		
		//cerr << solve1(a) << " " << solve2(a) << endl;
		printf("Case #%d: %s\n", tt, step == 3 ? "YES" : "NO");		
	}

	
	return 0;
}





































