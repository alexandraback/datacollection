#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int c[2510];

void lemon()
{
	int n; scanf("%d",&n);
	memset(c,0,sizeof c);
	rep(i,1,2*n-1)
		rep(j,1,n)
		{
			int x; scanf("%d",&x);
			c[x]^=1;
		}
	
	int z=0;
	rep(i,1,2500)
		if (c[i]==1)
		{
			printf("%d ",i); z++;
		}
		
	assert(z==n);
	printf("\n");
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

