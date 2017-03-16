#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

string tmp;
char s1[10010];
string s;
int si;
char re;
inline void mul(int p)
{
	if (re == '1')
	{
		re = s[p];
		return;
	}
	if (re == 'i')
	{
		if (s[p] == 'i') 
		{
			si ^= 1;
			re = '1';
		}
		if (s[p] == 'j')
		{
			re = 'k';
		}
		if (s[p] == 'k')
		{
			si ^= 1;
			re = 'j';
		}
		return;
	}
	if (re == 'j')
	{
		if (s[p] == 'i')
		{
			si ^= 1;
			re = 'k';
		}
		if (s[p] == 'j')
		{
			si ^= 1;
			re = '1';
		}
		if (s[p] == 'k')
		{
			re = 'i';
		}
		return;
	}
	if (re == 'k')
	{
		if (s[p] == 'i')
		{
			re = 'j';
		}
		if (s[p] == 'j')
		{
			si ^= 1;
			re = 'i';
		}
		if (s[p] == 'k')
		{
			si ^= 1;
			re = '1';
		}
		return;
	}
}

bool solve(int v)
{
	s = "";
	FOR(i, 0, v)
		s += tmp;
	si = 0;
	re = '1';
	int p = 0;
	while (p < s.size())
	{
		mul(p);
		if ((si == 0) && (re == 'i'))
		{
			break;
		}
		p++;
	}
	if (p == s.size())
	{
		return false;
	}
	p++;
	si = 0;
	re = '1';
	while (p < s.size())
	{
		mul(p);
		if ((si == 0) && (re == 'j'))
		{
			break;
		}
		p++;
	}
	if (p == s.size())
	{
		return false;
	}
	p++;
	si = 0;
	re = '1';
	while (p < s.size())
	{
		mul(p);
		p++;
	}
	if ((re == 'k') && (si == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tests;
	scanf("%d", &tests);
	for (int it = 1; it <= tests; ++it)
	{
		int l;
		LL x;
		cin >> l >> x;
		scanf("%s", s1);
		tmp = (string)s1;
		int v = 0;
		if (x<103)
			v = x;
		else
			v = 100 + (x % 4);
		bool f = false;
		FOR(i, v, v + 1)
		{
			if (i > x)
				break;
			f = solve(i);
			if (f)
				break;
		}
		if (f)
			printf("Case #%d: YES\n", it);
		else
			printf("Case #%d: NO\n", it);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}