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

int a[1005];

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
		int n;
		int ma = 0;
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			ma = max(ma,a[i]);
		}

		int res = ma;
		for (int i = 1;i <= ma;i++)
		{
			int temp = i;
			for (int j = 0;j < n;j++)
			{
				temp += (a[j] + i - 1) / i - 1;
			}
			res = min(res,temp);
		}

		printf("Case #%d: ",K);
		printf("%d\n",res);
	}


	return 0;
}
