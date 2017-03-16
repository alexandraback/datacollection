#include <cstdio>
#define REP(x,n) for(int x=0; x<(n); ++x)
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;

const char *R[] = {"X won", "O won", "Draw", "Game has not completed"};

char s[4][5];
int r;

bool win(char c)
{
	REP(i, 4) {
		int x = 0, y = 0;
		REP(j, 4) {
			if (s[i][j]==c || s[i][j]=='T') ++x;
			if (s[j][i]==c || s[j][i]=='T') ++y;
		}
		if (x==4 || y==4) return true;
	}
	int x = 0, y = 0;
	REP(i, 4) {
		if (s[i][i]==c || s[i][i]=='T') ++x;
		if (s[i][3-i]==c || s[i][3-i]=='T') ++y;
		if (x==4 || y==4) return true;
	}
	return false;
}

bool dot()
{
	REP(i, 4) REP(j, 4) if (s[i][j] == '.') return true;
	return false;
}


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		REP(i, 4) scanf("%s", s[i]);
		
		if (win('X')) r = 0;
		else if (win('O')) r = 1;
		else if (!dot()) r = 2;
		else r = 3;
		
		printf("Case #%d: %s\n", q, R[r]);
	}
	
	return 0;
}
