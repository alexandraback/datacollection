#include <stdio.h>
#include <algorithm>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define CL(a,x)         memset(a,x,sizeof(a))
#define scanI(i)                scanf("%d",&i)
#define printI(i)               printf("%d ",i)
#define printIln(i)             printf("%d\n",i)
#define scanS(i)                scanf("%s",&i)
#define printS(i)               printf("%s ",i)
#define printSln(i)             printf("%s\n",i)

int lawn[100][100];
int n, m, rmax[100], cmax[100];

bool possible()
{
	int mx;
	REP(i, n)
	{
		mx = lawn[i][0];
		FOR(j, 1, m) mx = max(mx, lawn[i][j]);
		rmax[i] = mx;
	}
	REP(i, m)
	{
		mx = lawn[0][i];
		FOR(j, 1, n) mx = max(mx, lawn[j][i]);
		cmax[i] = mx;
	}
	REP(i, n)
		REP(j, m)
		if (lawn[i][j] < rmax[i] && lawn[i][j] < cmax[j]) return false;
	return true;
}
int main()
{
	int T; scanI(T);
	REP(t, T)
	{
		scanI(n); scanI(m);
		REP(i, n)
			REP(j, m)
			scanI(lawn[i][j]);
		printf("Case #%d: ", t+1);
		if (possible()) printSln("YES");
		else printSln("NO");	
	}
    return 0;
}
