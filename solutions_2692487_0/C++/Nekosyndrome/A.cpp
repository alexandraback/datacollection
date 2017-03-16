#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1000005
using namespace std;
typedef long long LL;
int t,n,in[M],ans,cnt;
LL cur;
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%I64d %d",&cur,&n);
		cnt = 0;
		REP(i,1,n)scanf("%d",&in[i]);
		sort(in+1,in+n+1);

		if(cur==1)
		{
			printf("Case #%d: %d\n",tt,n);
			continue;
		}

		ans = n;
		REP(i,1,n)
		{
			if(cur > in[i])cur+=in[i];
			else
			{
				while(cur <= in[i])
				{
					cnt++;
					cur+=cur-1;
				}
				cur+=in[i];
			}

			ans = min(ans, cnt+n-i);
		}

		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

