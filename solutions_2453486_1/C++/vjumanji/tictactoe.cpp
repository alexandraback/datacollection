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

char G[4][4];

int check()
{
	int x = 0, o = 0;
	REP(i, 4) {
		x = 0, o=0; 
		REP(j, 4) 
			if (G[i][j]=='T') x++, o++; else if (G[i][j]=='X') x++; else if (G[i][j]=='O') o++;
		if (x==4) return 1;
		if (o==4) return 2;
	}
	REP(i, 4) {
		x = 0, o=0; 
		REP(j, 4) 
			if (G[j][i]=='T') x++, o++; else if (G[j][i]=='X') x++; else if (G[j][i]=='O') o++;
		if (x==4) return 1;
		if (o==4) return 2;
	}
	x =0, o=0;
	REP(i, 4)
		if (G[i][i]=='T') x++, o++; else if (G[i][i]=='X') x++; else if (G[i][i]=='O') o++;
	if (x==4) return 1;
	if (o==4) return 2;
	x =0, o=0;
	REP(i, 4)
		if (G[i][3-i]=='T') x++, o++; else if (G[i][3-i]=='X') x++; else if (G[i][3-i]=='O') o++;
	if (x==4) return 1;
	if (o==4) return 2;
	REP(i, 4) REP(j, 4) if (G[i][j]=='.') return 0;
	return 3;
}


int main()
{
	int T; scanI(T);
	REP(t, T)
	{
		REP(i, 4) scanS(G[i]);
		printf("Case #%d: ",t+1);
		switch(check())
		{
			case 0: printSln("Game has not completed"); break;
			case 1: printSln("X won"); break;
			case 2: printSln("O won"); break;
			case 3: printSln("Draw"); break;
		}
	}
    return 0;
}
