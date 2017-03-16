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

int T, n, m, x, y, pos, b[300];
string s[300], t, ans;
int a[300][300];

void dfs(int v)
{
	t += s[v];
	pos++;    
	if (pos == n)
		return;
	while (pos < n && a[v][b[pos]])
		dfs(b[pos]);
}
int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d", &T);
	forn(q, T)
	{
		scanf("%d%d\n", &n, &m);
		ans = "";
		forn(i, n)
		{
			cin >> s[i];         
		}
		forn(i, n)
			forn(j, n)
				a[i][j] = a[j][i] = 0;
		forn(i, m)
			scanf("%d%d", &x, &y), x--, y--, a[x][y] = a[y][x] = 1;
		forn(i, n)
			b[i] = i;
		do
		{                 	
			t = "";
			pos = 0;
			dfs(b[0]);
			if (pos == n && (ans == "" || ans > t))
				ans = t;
		}while (next_permutation(b, b + n));
		printf("Case #%d: %s\n", q + 1, ans.c_str());
	}
}


