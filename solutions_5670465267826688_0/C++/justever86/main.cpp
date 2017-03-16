#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define	sqr(a)		((a)*(a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	PER(i,n)	per(i,n,0)
#define	REP(i,n)	rep(i,0,n)
#define	clr(a)		memset((a),0,sizeof (a))
#define	SZ(a)		((int)((a).size()))
#define	ALL(x)		x.begin(),x.end()
#define	mabs(a)		((a)>0?(a):(-(a)))
#define	inf			(0x7fffffff)
#define	eps			1e-6

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;


#define TEST_LOCAL 1

char s[10005];
int d[10005][2];

int g(int x,int y)
{
	int r = 1;
	if (x < 0)
	{
		r *= -1;
		x *= -1;
	}

	if (y < 0)
	{
		r *= -1;
		y *= -1;
	}

	switch (x)
	{
	case 1:
		{
			switch (y)
			{
			case 1:
				r *= 1;
				break;
			case 2:
				r *= 2;
				break;
			case 3:
				r *= 3;
				break;
			case 4:
				r *= 4;
				break;
			}
		}
		break;
	case 2:
		{
			switch (y)
			{
			case 1:
				r *= 2;
				break;
			case 2:
				r *= -1;
				break;
			case 3:
				r *= 4;
				break;
			case 4:
				r *= -3;
				break;
			}
		}
		break;
	case 3:
		{
			switch (y)
			{
			case 1:
				r *= 3;
				break;
			case 2:
				r *= -4;
				break;
			case 3:
				r *= -1;
				break;
			case 4:
				r *= 2;
				break;
			}
		}
		break;
	case 4:
		{
			switch (y)
			{
			case 1:
				r *= 4;
				break;
			case 2:
				r *= 3;
				break;
			case 3:
				r *= -2;
				break;
			case 4:
				r *= -1;
				break;
			}
		}
		break;
	}

	return r;
}
int h(char c)
{
	switch (c)
	{
	case 'i':
		return 2;
	case 'j':
		return 3;
	case 'k':
		return 4;
	}
	return 1;
}

bool f(long long n,long long m)
{
	int t = 1;
	REP(i,n * m)
	{
		t = g(t,h(s[i % n]));
		d[i][0] = t;
	}
	t = 1;
	PER(i,n * m)
	{
		t = g(h(s[i % n]),t);
		d[i][1] = t;
	}

	int x = 1;
	int y = 1;
	int z = 1;
	for (int i = 1;i < n * m;i++)
	{
		x = d[i - 1][0];
		y = 1;
		for (int j = i + 1;j < n * m;j++)
		{
			y = g(y,h(s[(j - 1) % n]));
			z = d[j][1];
			if (x == 2 && y == 3 && z == 4)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("data.in","r",stdin);
#if TEST_LOCAL
	freopen("data.out","w",stdout);
#endif

	int T;
	scanf("%d",&T);

	for (int K = 1;K <= T;K++)
	{
		long long n,m;
		scanf("%I64d %I64d",&n,&m);
		scanf("%s",s);

		bool ret = f(n,m);
		
		printf("Case #%d: ",K);
		if (ret)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}


	return 0;
}
