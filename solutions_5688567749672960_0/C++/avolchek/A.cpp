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

const int inf = 1e9;
const int maxn = 1e6 + 5;
int dist[maxn];

int rev(int x)
{
	vector < int > a;
	while (x)
	{
		a.pb(x % 10);
		x /= 10;
	}
	x = 0;
	for (int y : a)
		x = 10 * x + y;
	return x;
}

int main()
{
	srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	cin >> t;
	//t = 100;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		//n = 333;
		
		for (int i = 0; i < maxn; i++)
			dist[i] = inf;
		dist[1] = 1;
		queue < int > q;
		q.push(1);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			if (v == n)
				break;
			if (v + 1 < maxn && dist[v + 1] == inf)
			{
				dist[v + 1] = dist[v] + 1;
				q.push(v + 1);
			}
			
			int x = rev(v);
			if (x < maxn && dist[x] == inf)
			{
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
		
		printf("Case #%d: %d\n", tt, dist[n]);
		cerr << tt << endl;
	}
	
	return 0;
}



































