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

int n,m;
int a[105][105];

int check(int x,int y)
{
	int flag = 1;
	REP(i,n)
	{
		if (a[i][y] > a[x][y])
		{
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		return 1;
	}
	flag = 1;
	REP(i,m)
	{
		if (a[x][i] > a[x][y])
		{
			flag = 0;
			break;
		}
	}
	if (flag)
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
		scanf("%d %d",&n,&m);
		REP(i,n)
		{
			REP(j,m)
			{
				scanf("%d",&a[i][j]);
			}
		}

		int res = 1;
		REP(i,n)
		{
			if (!res)
			{
				break;
			}
			REP(j,m)
			{
				res = check(i,j);
				if (!res)
				{
					break;
				}
			}
		}
		printf("Case #%d: ",K);
		puts(res ? "YES" : "NO");
	}

	return 0;
}
