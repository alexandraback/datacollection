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

vector<pair<pair<int,int>,int> > v;
int b[1005];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int CASE;
	scanf("%d",&CASE);
	REP(K,CASE)
	{
		int n;
		v.clear();
		scanf("%d",&n);
		REP(i,n)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			v.push_back(make_pair(make_pair(y,x),i));
		}
		sort(v.begin(),v.end());

		int cnt = 2 * n;
		int star = 0;
		int flag = 1;
		int res = 0;
		
		clr(b);
		while (cnt != star && flag)
		{
			flag = 0;

			REP(i,n)
			{
				if (b[v[i].second] == 1)
				{
					if (v[i].first.first <= star)
					{
						b[v[i].second] = 2;
						star += 1;
						flag = 1;
						res++;
						break;
					}
				}
			}
			if (flag)
			{
				continue;
			}

			REP(i,n)
			{
				if (b[v[i].second] == 0)
				{
					if (v[i].first.first <= star)
					{
						b[v[i].second] = 2;
						star += 2;
						flag = 1;
						res++;
						break;
					}
				}
			}
			if (flag)
			{
				continue;
			}

			PER(i,n)
			{
				if (b[v[i].second] == 0)
				{
					if (v[i].first.second <= star)
					{
						b[v[i].second] = 1;
						star += 1;
						flag = 1;
						res++;
						break;
					}
				}
			}
			if (flag)
			{
				continue;
			}
		}

		printf("Case #%d: ",K + 1);
		if (!flag)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n",res);
		}
	}

	return 0;
}
