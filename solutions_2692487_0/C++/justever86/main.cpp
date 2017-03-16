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
#define max(a,b)	((a)>(b)?(a):(b))

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

int dp[105][105];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	rep(K,1,CASE + 1)
	{
		long long a,n;
		scanf("%I64d %I64d",&a,&n);
		clr(dp);
		vector<long long> v;
		REP(i,n)
		{
			long long t;
			scanf("%I64d",&t);
			v.push_back(t);
		}

		sort(v.begin(),v.end());

		dp[0][0] = a;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j <= n;j++)
			{
				if (dp[i][j] > v[i])
				{
					dp[i + 1][j] = max(dp[i + 1][j],dp[i][j] + v[i]);
				}
				else
				{
					if (j < n)
					{
						dp[i + 1][j + 1]= max(dp[i + 1][j],dp[i][j]);
						dp[i][j + 1] = max(dp[i][j + 1],dp[i][j] * 2 - 1);
					}
				}
			}
		}
		int res = -1;
		for (int i = 0;i <= n;i++)
		{
			if (dp[n][i] != 0)
			{
				res = i;
				break;
			}
		}

		printf("Case #%d: ",K);
		printf("%d\n",res);
	}

	return 0;
}
