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

long long gcd(long long x,long long y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
#if 1
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int CASE;
	scanf("%d",&CASE);
	
	for (int K = 1;K <= CASE;K++)
	{
		long long p,q;
		scanf("%I64d/%I64d",&p,&q);

		long long r = gcd(p,q);
		p /= r;
		q /= r;
		if ((p > q) || (q & (q - 1LL)) != 0LL)
		{
			printf("Case #%d: ",K);
			printf("impossible\n");
			continue;
		}

		long long temp = 1LL;
		int res = 0;
		while (1)
		{
			if (p >= q / temp)
			{
				break;
			}

			res++;
			temp <<= 1;
		}

		printf("Case #%d: ",K);
		printf("%d\n",res);
	}

	return 0;
}
