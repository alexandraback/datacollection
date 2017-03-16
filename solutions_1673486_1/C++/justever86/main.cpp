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
double a[100005];
double p[100005];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	REP(K,CASE)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		REP(i,n)
		{
			scanf("%lf",&a[i]);
		}

		double t = 1.0;
		double res;
		res = (m + 2);

		REP(i,n + 1)
		{
			double temp = 0.0;
			temp += ((m - i) + (n - i) + 1) * t;
			temp += ((m - i) + (n - i) + 1 + m + 1) * (1 - t);
			res = min(temp,res);
			t *= (a[i]);
		}

		printf("Case #%d: ",K + 1);
		printf("%lf\n",res);
	}

	return 0;
}
