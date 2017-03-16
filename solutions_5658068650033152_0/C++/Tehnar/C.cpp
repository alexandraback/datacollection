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
 
int n, m, t, a[30][30], used[30][30], s, k, tmp, ans, turn[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool dfs(int x, int y)
{
	if (a[x][y])
		return 1;
	//cerr << x << " " << y << " " << used[x][y] << endl;
	used[x][y] = 1;
	if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
	{
		used[x][y] = 2;
		return 0;
	}
	used[x][y] = 1;
	forn(i, 4)
	{
		int dx = x + turn[i][0], dy = y + turn[i][1];
		if (used[dx][dy] == 2 || (!used[dx][dy] && !dfs(dx, dy)))
		{
			used[x][y] = 2;
			return 0;
		}

	}
	return 1;
}
int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout); 
	scanf("%d", &t);
	forn(q, t)
	{
		scanf("%d%d%d", &n, &m, &k);
		//n++, m++;
		ans = n * m;
		cerr << q << endl;
		forn(x, 1<<(n*m))
		{
			s = tmp = 0;
			forn(i, n)
				forn(j, m)
					if (x & (1<<(i * m + j)))
						a[i][j] = 1, s++;
					else
						a[i][j] = 0;
			if (s >= ans)
				continue;
			forn(i, n)
				forn(j, m)
					used[i][j] = 0;
			forn(i, n)
			{
				if (tmp >= k)	
				{
					ans = s;
			       	break;
			    }
				forn(j, m)
				{
					if (dfs(i, j))
						tmp++;			
					if (tmp >= k)	
					{
						ans = s;
			        	break;
			        }
				}
			}
			//cerr << tmp << endl;
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
}
 
 