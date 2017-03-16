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
		long long a,b,k;
		scanf("%I64d %I64d %I64d",&a,&b,&k);

		long long res = 0;
		REP(i,a)
		{
			REP(j,b)
			{
				if ((i & j) < k)
				{
					res++;
				}
			}
		}

		printf("Case #%d: ",K);
		printf("%I64d\n",res);
	}

	return 0;
}
