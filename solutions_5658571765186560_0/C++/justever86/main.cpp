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

int f(int n,int r,int c)
{
	if (n == 1)
	{
		return true;
	}
	if (r % n != 0 && c % n != 0)
	{
		return false;
	}

	if (n == 2)
	{
		return true;
	}

	if (n == 3)
	{
		if (r == 1 || c == 1)
		{
			return false;
		}
		return true;
	}
	if (n == 4)
	{
		if (r >= 3 && c >= 3)
		{
			return true;
		}
		return false;
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
		int n,r,c;
		scanf("%d %d %d",&n,&r,&c);
		int ret = f(n,r,c);
		printf("Case #%d: ",K);
		if (ret)
		{
			puts("GABRIEL");
		}
		else
		{
			puts("RICHARD");
		}
	}


	return 0;
}
