#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 200
using namespace std;
typedef long long LL;
int t,n,d[M],h[M],m[M];
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%d",&n);
		REP(i,1,n) scanf("%d %d %d",&d[i],&m[i],&h[i]);

		if(n<=1)
		{
			printf("Case #%d: 0\n",tt);
		}
		else
		{
			if(d[1]>d[2])
			{
				swap(d[1], d[2]);
				swap(m[1], m[2]);
				swap(h[1], h[2]);
			}
			double v1 = (360-d[1])/360.0 * m[1];
			double v2 = (360-d[2])/360.0 * m[2];
			
			printf("Case #%d: ",tt);
			if(d[1]==d[2] && m[1]==m[2]) printf("%d\n", min(h[1],h[2]));
			else if(v1 >= v2) printf("%d\n", h[1]);
			else puts("0");
		}
	}
	return 0;
}

