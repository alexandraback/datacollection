#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(int)n; i++)
typedef long long int64;

char t[5][5];

int win(int a, int b, int da, int db) {
	if (a<0 || b<0 || a>=4 || b>=4) return 3;
	if (t[a][b]=='.') return 0;
	if (t[a][b]=='T') return 3 & win(a+da,b+db,da,db);
	if (t[a][b]=='X') return 1 & win(a+da,b+db,da,db);
	return 2 & win(a+da,b+db,da,db);
}

int main() {
	int nt;

	scanf("%d",&nt);
	REP(ct,nt) {
		bool full=1;
		REP(i,4)
			REP(j,4) {
				scanf(" %c",&t[i][j]);
				full&=(t[i][j]!='.');
			}
			

		int st=win(0,0,1,1) | win(0,3,1,-1);
		REP(i,4)
			st |= win(i,0,0,1) | win(0,i,1,0);

		printf("Case #%d: ", ct+1);
		if (st) printf("%c won\n",(st==1)?'X':'O');
		else if (full) printf("Draw\n");
		else printf("Game has not completed\n");
	}
				
	return 0;
}
