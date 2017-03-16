#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

char s[8][8];

int cx[111][5], cy[111][5], nc;

int main() {
	nc = 0;
	FOR(i,0,4){
		FOR(j,0,4){
			cx[nc][j] = i;
			cy[nc][j] = j;
		}
		nc++;
		FOR(j,0,4){
			cx[nc][j] = j;
			cy[nc][j] = i;
		}
		nc++;
	}
	FOR(j,0,4){
		cx[nc][j] = j;
		cy[nc][j] = j;
	}
	nc++;
	FOR(j,0,4){
		cx[nc][j] = 3-j;
		cy[nc][j] = j;
	}
	nc++;
	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	FOR(i,0,4)scanf("%s",s[i]);
	bool hvdot = false;
	bool win1 = false, win2 = false;
	FOR(i,0,nc){
		int n0=0, n1=0, n2=0;
		FOR(j,0,4){
			if(s[cx[i][j]][cy[i][j]] == 'T') n0++;
			if(s[cx[i][j]][cy[i][j]] == 'X') n1++;
			if(s[cx[i][j]][cy[i][j]] == 'O') n2++;
			if(s[cx[i][j]][cy[i][j]] == '.') hvdot = true;
		}
		if(n0 + n1 == 4) win1 = true;
		if(n0 + n2 == 4) win2 = true;
	}
	printf("Case #%d: ", tt);
	if(win1) printf("X won\n");
	else if(win2) printf("O won\n");
	else if(hvdot) printf("Game has not completed\n");
	else printf("Draw\n");
}	
return 0;
}


