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
int pr[maxn];

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


int naive(int n)
{
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
			pr[v + 1] = v;
			q.push(v + 1);
		}
		
		int x = rev(v);
		if (x < maxn && dist[x] == inf)
		{
			dist[x] = dist[v] + 1;
			pr[x] = v;
			q.push(x);
		}
	}
	
	/*int v = n;
	while (v != 1)
	{
		cout << v << endl;
		v = pr[v];
	}*/
	
	return dist[n];
}

ll nines(ll len)
{
	if (len == 1)
		return 9;
		
	ll ans = 0;
		
	ll x = 1;
	for (int i = 0; i < len / 2; i++)
		x *= 10LL;
	x -= 2;
	
	ans += x;
	ans += 1;
	
	x = 1;
	for (int i = 0; i < len - (len / 2); i++)
		x *= 10LL;
		
	ans += x + nines(len - 1);
		
	return ans;
}

ll smart(ll n, int g)
{
	if (n < 100)
		return naive(n);
	if (n % 10 == 0)
	{
		return smart(n - 1, g) + 1;
	}
	
	vector < int > a;
	while (n)
	{
		a.pb(n % 10);
		n /= 10;
	}
	
	reverse(a.begin(), a.end());
	
	ll ans = 1e18;
	
	if (a[0] == 1)
	{
		ll x = 0;
		for (int i = 1; i < a.size(); i++)
			x = x * 10 + a[i];
		ans = min(ans, x + 1 + nines(a.size() - 1));
	}
	
	
	ll c = 0;
	ll x = 0;
	int len = a.size();
	for (int i = 0; i + (len + g) / 2 < a.size(); i++)
	{
		x = x * 10 + a[(len + g) / 2 + i];
		a[i + (len + g) / 2] = 0;
	}
		
	
	c += x - 1;
	c++;
	reverse(a.begin(), a.end());
	
	x = 0;
	for (int i = 0; i + (len) / 2 < a.size(); i++)
		x = x * 10 + a[(len) / 2 + i];
		
	//cerr << len << endl;
		
	c += x + 1;
	c += nines(len - 1);
	
	ans = min(ans, c);
	
	return ans;
}


int main()
{
	//srand(time(NULL));
	//gen();
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	cin >> t;
	//t = 100000;
	for (int tt = 1; tt <= t; tt++)
	{
		ll n;
		cin >> n;
		//n = rand() % 1000000 + 1;
		//n = 333;
		
		//ll x = naive(n);
		ll y = min(smart(n, 0), smart(n, 1));
		
		//cerr << n << " " << x << " " << y << endl;
		//assert(x == y);
		
		printf("Case #%d: %lld\n", tt, y);
		cerr << tt << endl;
	}
	
	return 0;
}



































