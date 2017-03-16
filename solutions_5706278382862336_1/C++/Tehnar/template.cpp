#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
 
 
#define FNAME ""
 
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < b; i++)
#define gcd __gcd
 
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
 
using namespace std;
 
template <class T> T sqr(const T &a) {return a * a;}
 
int t, d, boo, ans;
LL x, y;
int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout); 
	scanf("%d\n", &t);
	forn(q, t)
	{
		printf("Case #%d: ", q + 1);
		scanf("%I64d/%I64d\n", &x, &y);
		d = gcd(x, y);
		x /= d, y /= d;
		boo = 0;
		forn(i, 40)
			if (y == 1ll<<i)
			{
				boo = 1;
				y *= 1ll<<(40 - i);
				x *= 1ll<<(40 - i);
				break;
			}
		if (!boo)
		{
			puts("impossible");
			continue;	
		}
		ans = 40;
		cerr << x << " " << y << endl;             
		fornr(i, 40)
		{
			if (1ll<<(40 - i) <= x)
				ans = i;
		}
		printf("%d\n", ans);
	}
}
 
 