#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

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

void lemon()
{
	int x,n,m; scanf("%d%d%d",&x,&n,&m);
	if (n>m) swap(n,m);
	if (n*m%x!=0 || x>max(n,m))
	{
		printf("RICHARD\n");
		return;
	}
	if (n==1)
	{
		if (x<=2)
		{
			printf("GABRIEL\n");
			return;
		}
		else
		{
			printf("RICHARD\n");
			return;
		}
	}
	if (n==2)
	{
		//X=4
		//.**
		//**.
		//X>=5
		//*.*
		//***
		if (x>=4)
		{
			printf("RICHARD\n");
			return;
		}
		else
		{
			printf("GABRIEL\n");
			return;
		}
	}
	//X>=7
	//***
	//*.*
	//**.
	if (n==3)
	{
		//X=6
		//..**
		//..*.
		//***.
		if (x>=6)
		{
			printf("RICHARD\n");
			return;
		}
		else
		{
			printf("GABRIEL\n");
			return;
		}
	}
	if (x>=7)
	{
		printf("RICHARD\n");
		return;
	}
	else
	{
		printf("GABRIEL\n");
		return;
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("D.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

