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

int a[32][32];


int main()
{
	srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	cin >> t;
	//t = 1000;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		vector < pair < ld, ld > > a;
		const ld eps = 1e-10;
		
		int ans = 1;
		
		for (int i = 0; i < n; i++)
		{
			int d, h, m;
			cin >> d >> h >> m;
			for (int j = 0; j < h; j++)
			{
				a.pb(mp(d, 360.0 / m));
				m++;
			}
		}
		
		if (a.size() == 2)
		{
			ld t1 = (360.0 - a[0].fst) / a[0].snd;
			ld t2 = (360.0 - a[1].fst) / a[1].snd;
			
			if (t1 > t2)
			{
				swap(a[0], a[1]);
				swap(t1, t2);
			}
			
			ld p2 = a[1].fst + a[1].snd * t1;
			
			
			
			if (p2 / max(1e-14l, (a[0].snd - a[1].snd)) > eps + (360.0 - p2) / a[1].snd)
				ans = 0;
		}
		else
		{
			ans = 0;
		}
		
		
		printf("Case #%d: %d\n", tt, ans);
		cerr << tt << endl;
	}
	
	return 0;
}





































