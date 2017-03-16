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
long long v[10005];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	rep(K,1,CASE + 1)
	{
		long long e,r,n;
		scanf("%I64d %I64d %I64d",&e,&r,&n);
		r = min(e,r);
		long long t_v = 0;
		long long res = 0;
		REP(i,n)
		{
			scanf("%I64d",&v[i]);
			t_v = max(t_v,v[i]);
		}
		int now_i = -1;
		REP(i,n)
		{
			if (v[i] != t_v)
			{
				
			}
			else
			{
				now_i = i;
				break;
			}
		}

		int x_v = 0;
		int x_i = -1;
		int z_i = now_i;
		while (z_i > 0)
		{
			REP(i,z_i)
			{
				if (v[i] >= x_v)
				{
					x_v = v[i];
					x_i = i;
				}
			}
			if ((z_i - x_i) * r >= e)
			{
				now_i = x_i;
			}
			else
			{
				res += (z_i - x_i) * r * x_v;
			}
			z_i = x_i;
			x_v = 0;
		}
		res += e * v[now_i];

		while (now_i < n - 1)
		{
			t_v = 0;
			int t_i = now_i + 1;
			rep(i,now_i + 1,n)
			{
				if (t_v < v[i])
				{
					t_v = v[i];
					t_i = i;
				}
			}

			if ((t_i - now_i) * r <= e)
			{
				res += (t_i - now_i) * r * t_v;
				now_i = t_i;
			}
			else
			{
				int ff = (t_i - now_i) * r - e;
				int rr = (e + r - 1) / r;
				int p_v = 0;
				int p_i = now_i + 1;
				rep(i,now_i + 1,now_i + rr)
				{
					if (p_v < v[i])
					{
						p_v = v[i];
						p_i = i;
					}
				}
				if ((p_i - now_i) * r >= ff)
				{
					res += ff * p_v;
					res += e * t_v;
					now_i = t_i;
				}
				else
				{
					res += (p_i - now_i) * r * p_v;
					now_i = p_i;
				}
			}
		}
		

		printf("Case #%d: ",K);
		printf("%I64d\n",res);
	}

	return 0;
}
