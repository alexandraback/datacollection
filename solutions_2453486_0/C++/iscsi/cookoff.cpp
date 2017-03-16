#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;


int main()
{
#ifdef HOME
	freopen ("A-small-attempt0.in","r",stdin);
	freopen ("A-small-attempt0.out","w",stdout);
#endif
	int T;
	cin >> T;
	char c[5][5];
	FOR(testcase,1,T+1)
	{
		bool x_won=0,o_won=0,completed=1;
		REP(i,4) scanf("%s",c[i]);
		REP(i,4) REP(j,4) if(c[i][j]=='.') completed=0;
		REP(i,4) 
		{
			int X_cnt=0;
			int O_cnt=0;
			REP(j,4)
				if(c[i][j]=='T') ++X_cnt,++O_cnt;
				else if(c[i][j]=='X') ++X_cnt;
				else if(c[i][j]=='O') ++O_cnt;
				if(X_cnt==4) x_won=1;
				if(O_cnt==4) o_won=1;
		}
		REP(j,4) 
		{
			int X_cnt=0;
			int O_cnt=0;
			REP(i,4)
			{
				if(c[i][j]=='T') ++X_cnt,++O_cnt;
				else if(c[i][j]=='X') ++X_cnt;
				else if(c[i][j]=='O') ++O_cnt;
			}
			if(X_cnt==4) x_won=1;
			if(O_cnt==4) o_won=1;
		}
		int X_cnt=0;
		int O_cnt=0;
		REP(i,4)
		{
			if(c[i][i]=='T') ++X_cnt,++O_cnt;
			else if(c[i][i]=='X') ++X_cnt;
			else if(c[i][i]=='O') ++O_cnt;
		}
		if(X_cnt==4) x_won=1;
		if(O_cnt==4) o_won=1;
		X_cnt=0;
		O_cnt=0;
		REP(i,4)
		{
			if(c[3-i][i]=='T') ++X_cnt,++O_cnt;
			else if(c[3-i][i]=='X') ++X_cnt;
			else if(c[3-i][i]=='O') ++O_cnt;
		}
		if(X_cnt==4) x_won=1;
		if(O_cnt==4) o_won=1;
		if(x_won)
			printf("Case #%d: X won\n",testcase);
		else if(o_won)
			printf("Case #%d: O won\n",testcase);
		else if(completed)
			printf("Case #%d: Draw\n",testcase);
		else
			printf("Case #%d: Game has not completed\n",testcase);

	}
	return 0;
} 