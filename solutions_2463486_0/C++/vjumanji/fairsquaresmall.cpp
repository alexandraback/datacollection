#include <stdio.h>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define scanI(i)                scanf("%d",&i)
#define printI(i)               printf("%d ",i)
#define printIln(i)             printf("%d\n",i)
#define scanS(i)                scanf("%s",&i)
#define printS(i)               printf("%s ",i)
#define printSln(i)             printf("%s\n",i)

int fairsquare[] = {1,4,9,121,484};

int loc(int x)
{
	REP(i, 5) if (fairsquare[i]>x) return i-1;
	return 4;
}

int main()
{
	int T, a, b, ai, bi, r; scanI(T);
	REP(t, T)
	{
		scanI(a); scanI(b);
		ai = loc(a);
		bi = loc(b);
		printf("Case #%d: ", t+1);
		r = bi-ai;
		if (fairsquare[ai]==a) r++;
		printIln(r);
	}
    return 0;
}
