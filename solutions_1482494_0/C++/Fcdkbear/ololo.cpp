#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

using namespace std;
int a[1010];
int b[1010];
vector<pair<int, pnt> > c;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int n;
		scanf("%d",&n);
		FOR(i,0,n)
			scanf("%d%d",&a[i],&b[i]);
		int res=2000000000;
		FOR(i,0,(1<<n))
		{
			c.clear();
			FOR(j,0,n)
			{
				c.push_back(mp(a[j],mp(0,j)));
				c.push_back(mp(b[j],mp(1,j)));
			}
			sort(c.begin(),c.end());
			int cur=0;
			int cres=0;
			FOR(j,0,c.size())
			{
				int v=c[j].second.second;
				if (c[j].second.first==0)
				{
					if ((i>>v)&1)
					{
						if (cur<c[j].first)
						{
							cres=2000000000;
							break;
						}
						cur++;
						cres++;
					}
				}
				else
				{
					if ((i>>v)&1)
					{
						if (cur<c[j].first)
						{
							cres=2000000000;
							break;
						}
						cur++;
						cres++;
					}
					else
					{
						if (cur<c[j].first)
						{
							cres=2000000000;
							break;
						}
						cur+=2;
						cres++;
					}
				}
			}
			res=MIN(res,cres);
		}
		printf("Case #%d: ",test);
		if (res>=2000000000)
			printf("Too Bad\n");
		else
			printf("%d\n",res);
	}
	return 0;
}