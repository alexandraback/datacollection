//Grzegorz Prusak
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(int i=(p); i>=(k); --i)

typedef long long LL;

char A[4][5];

bool is(char &a, char b)
{ return a==b || a=='T'; }

bool win(char c)
{
	REP(i,4)
	{
		bool ok = 1;
		REP(j,4) if(!is(A[i][j],c)) ok = 0;
		if(ok) return 1;
	}

	REP(i,4)
	{
		bool ok = 1;
		REP(j,4) if(!is(A[j][i],c)) ok = 0;
		if(ok) return 1;
	}

	{
		bool ok = 1;
		REP(i,4) if(!is(A[i][i],c)) ok = 0;
		if(ok) return 1;
	}
	
	{
		bool ok = 1;
		REP(i,4) if(!is(A[i][3-i],c)) ok = 0;
		if(ok) return 1;
	}
	return 0;
}

bool full()
{
	int c = 0;
	REP(i,4) REP(j,4) if(A[i][j]=='.') c++;
	return !c;
}

int main()
{
	int t; scanf("%d",&t);
	FOR(_,1,t)
	{
		printf("Case #%d: ",_);
		REP(i,4) scanf(" %s",A[i]);
		if(win('X')) puts("X won");
		else if(win('O')) puts("O won");
		else if(full()) puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
