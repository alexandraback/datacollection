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

int a[15];

int f(int x,int y,int z,int t)
{
	if (t % x == 0)
	{
		t /= x;
	}
	if (t % y == 0)
	{
		t /= y;
	}
	if (t % z == 0)
	{
		t /= z;
	}
	return t == 1;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	rep(K,1,CASE + 1)
	{
		int r,n,m,kk;
		scanf("%d %d %d %d",&r,&n,&m,&kk);

		printf("Case #%d: \n",K);
		REP(i,r)
		{
			REP(i,kk)
			{
				scanf("%d",&a[i]);
			}
			int flag = 0;
			char res[5];
			clr(res);
			rep(i,2,m + 1)
			{
				int x = i;
				rep(j,2,m + 1)
				{
					int y = n > 1 ? j : 1;
					rep(k,2,m + 1)
					{
						int z = n > 2 ? k : 1;
						int fff = 0;
						REP(o,kk)
						{
							if (!f(x,y,z,a[o]))
							{
								fff = 1;
								break;
							}
						}

						if (fff == 0)
						{
							res[0] = i + '0';
							if (n > 1)
							{
								res[1] = j + '0';
							}
							if (n > 2)
							{
								res[2] = k + '0';
							}
							flag = 1;
							break;
						}
					}
					if (flag)
					{
						break;
					}
				}
				if (flag)
				{
					break;
				}
			}
			printf("%s\n",res);
		}

		
	}

	return 0;
}
