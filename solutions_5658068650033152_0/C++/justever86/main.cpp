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

int count(int x)
{
	int temp = 0;
	while (x)
	{
		temp += x % 2;
		x /= 2;
	}

	return temp;
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
		int n,m,kk;
		scanf("%d %d %d",&n,&m,&kk);
		
		int t = n * m;
		int res = kk;
		for (int x = 0; x < (1 << t);x++)
		{
			int mp[30][30];
			clr(mp);
			if (count(x) < kk)
			{
				continue;
			}

			REP(i,t)
			{
				if (x & (1 << i))
				{
					int a = i / m;
					int b = i % m;
					mp[a][b] = 1;
				}
			}

			int temp = 0;
			REP(i,n)
			{
				REP(j,m)
				{
					if (mp[i][j] == 1)
					{
						int flag = 0;
						for (int k = j - 1;k >= 0;k--)
						{
							if (mp[i][k] == 1)
							{
								flag |= 1;
								break;
							}
						}
						for (int k = j + 1;k < m;k++)
						{
							if (mp[i][k] == 1)
							{
								flag |= 2;
								break;
							}
						}

						for (int k = i - 1;k >= 0;k--)
						{
							if (mp[k][j] == 1)
							{
								flag |= 4;
								break;
							}
						}
						for (int k = i + 1;k < n;k++)
						{
							if (mp[k][j] == 1)
							{
								flag |= 8;
								break;
							}
						}

						if (flag != 15)
						{
							temp++;
						}
					}
				}
			}

			res = min(res,temp);
		}

		printf("Case #%d: ",K);
		printf("%d\n",res);
	}

	return 0;
}
