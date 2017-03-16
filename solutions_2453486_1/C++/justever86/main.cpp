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
#include <cassert>

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

char s[5][5];

int check(char c)
{
	REP(i,4)
	{
		int flag = 1;
		REP(j,4)
		{
			if (!(s[i][j] == c || s[i][j] == 'T'))
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			return 1;
		}

		flag = 1;
		REP(j,4)
		{
			if (!(s[j][i] == c || s[j][i] == 'T'))
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			return 1;
		}
	}

	int flag = 1;
	REP(i,4)
	{
		if (!(s[i][i] == c || s[i][i] == 'T'))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		{
			return 1;
		}

	flag = 1;
	REP(i,4)
	{
		if (!(s[i][3 - i] == c || s[i][3 - i] == 'T'))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		return 1;
	}

	return 0;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	for (int K = 1;K <= CASE;K++)
	{
		gets(s[0]);
		REP(i,4)
		{
			gets(s[i]);
		}

		int t1 = check('X');
		int t2 = check('O');

		printf("Case #%d: ",K);
		if (t1 && !t2)
		{
			puts("X won");
		}
		else if (!t1 && t2)
		{
			puts("O won");
		}
		else if (!t1 && !t2)
		{
			int flag = 0;
			REP(i,4)
			{
				REP(j,4)
				{
					if (s[i][j] == '.')
					{
						flag = 1;
						break;
					}
				}
			}
			puts(flag ? "Game has not completed" : "Draw");
		}
		else
		{
			assert(!(t1 && t2));
			puts("Draw");
		}
	}

	return 0;
}
