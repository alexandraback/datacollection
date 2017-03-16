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

double dp[1005][1005];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	rep(K,1,CASE + 1)
	{
		long long n,x,y;
		scanf("%I64d %I64d %I64d",&n,&x,&y);
		x = mabs(x);
		long long cnt = 0;
		long long t = 0;
		double res;
		for (;cnt + t * 2 + 1 <= n && t <= x + y;t += 2)
		{
			cnt += t * 2 + 1;
		}
		

		if (cnt + t * 2 + 1 > n && t < x + y)
		{
			res = 0;
		}
		else if (t > x + y)
		{
			res = 1;
		}
		else
		{
			long long r = n - cnt;
			clr(dp);
			dp[0][0] = 1.0;
			for (long long i = 0;i < r;i++)
			{
				for (long long j = 0;j <= i;j++)
				{
					if (j < t)
					{
						dp[j + 1][i - j] += dp[j][i - j] * 0.5;
					}
					else
					{
						dp[j][i - j + 1] += dp[j][i - j] * 0.5;
					}
					if (i - j < t)
					{
						dp[j][i - j + 1] += dp[j][i - j] * 0.5;
					}
					else
					{
						dp[j + 1][i - j] += dp[j][i - j] * 0.5;
					}
				}
			}
			res = 0;
			for (int i = y + 1;i <= t;i++)
			{
				res += dp[i][r - i];
			}
		}
		

		printf("Case #%d: ",K);
		printf("%lf\n",res);
	}

	return 0;
}
