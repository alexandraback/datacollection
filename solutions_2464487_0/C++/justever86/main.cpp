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
#define min(a,b)	((a)<(b)?(a):(b))

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	rep(K,1,CASE + 1)
	{
		long long rr,t;
		scanf("%I64d %I64d",&rr,&t);

		long long l = 1;
		long long r = min(707106780,t / rr);
		long long res = 1;
		while (l <= r)
		{
			long long mid = (l + r) / 2;
			long long tt = mid * (rr + rr + mid * 2 - 1);
			if (tt > t)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
				res = mid;
			}
		}

		printf("Case #%d: ",K);
		printf("%I64d\n",res);
	}

	return 0;
}
