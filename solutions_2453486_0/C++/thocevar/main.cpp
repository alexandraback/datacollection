#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define mp make_pair
#define INIT(v,x) memset(v,x,sizeof(v))
#define REP(i,n) for (int i=0;i<(n);i++)
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)

typedef pair<int,int> PII;
typedef long long int64;

int tests;
char b[9][9];

int valid(char x, char p) {
	return x==p || x=='T';
}

int row(int i, char p) {
	int ok=1;
	REP (j,4) if (!valid(b[i][j],p)) ok=0;
	return ok;
}

int col(int j, char p) {
	int ok=1;
	REP (i,4) if (!valid(b[i][j],p)) ok=0;
	return ok;
}

int diag1(char p) {
	int ok=1;
	REP (i,4) if (!valid(b[i][i],p)) ok=0;
	return ok;
}

int diag2(char p) {
	int ok=1;
	REP (i,4) if (!valid(b[i][3-i],p)) ok=0;
	return ok;
}

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	scanf("%d",&tests);
	REP (test,tests) {
		REP (i,4) scanf("%s",b[i]);
		char win='?';
		int full=1;
		REP (i,4) REP (j,4) if (b[i][j]=='.') full=0;
		// row
		REP (i,4) {
			if (row(i,'O')) win='O';
			if (row(i,'X')) win='X';
		}
		// col
		REP (j,4) {
			if (col(j,'O')) win='O';
			if (col(j,'X')) win='X';
		}
		// diag
		if (diag1('O')) win='O';
		if (diag1('X')) win='X';
		if (diag2('O')) win='O';
		if (diag2('X')) win='X';

		printf("Case #%d: ",test+1);
		if (win=='?') {
			if (full) printf("Draw\n");
			else printf("Game has not completed\n");
		} else printf("%c won\n",win);
	}
	return 0;
}
