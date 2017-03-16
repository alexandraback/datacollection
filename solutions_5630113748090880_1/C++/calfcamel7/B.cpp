#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define clr(a,b) memset(a,b,sizeof(a));
#define MP(x,y) std::make_pair(x,y)
#define PB(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define REP(x,z,y) for(int x = (int)(z), __END__ = (int)(y); x <= __END__; x++)
#define BB second
#define AA first

int a[2505];
int main()
{
	int _T;
	scanf("%d",&_T);
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		int n;
		scanf("%d",&n);
		int x;
		clr(a,0);
		FOR(i,n) FOR(j,2 * n - 1)
		{
			scanf("%d",&x);
			a[x] ^= 1;
		}
		printf("Case #%d:", CAS);
		FORR(i,2500)
			if(a[i])
				printf(" %d", i);
		puts("");
	}
}