#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN
#define INF
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int test,X,O,ile_X,ile_O;
char t[4][4];

int main() {
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		O = X = 0;
		REP(i,4) scanf(" %s",t[i]);
		
		//poziome
		REP(i,4) {
			ile_X = ile_O = 0;
			REP(j,4) {
				if (t[i][j] == 'X') ++ile_X;
				if (t[i][j] == 'O') ++ile_O;
				if (t[i][j] == 'T') ++ile_X,++ile_O;
			}
			if (ile_X == 4) X = 1;
			if (ile_O == 4) O = 1;
		}
		
		//pionowe
		REP(i,4) {
			ile_X = ile_O = 0;
			REP(j,4) {
				if (t[j][i] == 'X') ++ile_X;
				if (t[j][i] == 'O') ++ile_O;
				if (t[j][i] == 'T') ++ile_X,++ile_O;
			}
			if (ile_X == 4) X = 1;
			if (ile_O == 4) O = 1;
		}
		
		//skosy
		ile_X = ile_O = 0;
		REP(j,4) {
			if (t[j][j] == 'X') ++ile_X;
			if (t[j][j] == 'O') ++ile_O;
			if (t[j][j] == 'T') ++ile_X,++ile_O;
		}
		if (ile_X == 4) X = 1;
		if (ile_O == 4) O = 1;
		
		ile_X = ile_O = 0;
		REP(j,4) {
			if (t[j][4-j-1] == 'X') ++ile_X;
			if (t[j][4-j-1] == 'O') ++ile_O;
			if (t[j][4-j-1] == 'T') ++ile_X,++ile_O;
		}
		if (ile_X == 4) X = 1;
		if (ile_O == 4) O = 1;
		
		if (X+O) {
			if (X) puts("X won");
				else puts("O won");
		}
		else {
			bool remis = true;
			REP(i,4) REP(j,4) if (t[i][j] == '.') remis = false;
			if (remis) puts("Draw"); else puts("Game has not completed");
		}
	}
	return 0;
}
