#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf



char board[4][5];

bool won(char c) {
	int cnt[10];
	memset(cnt, 0, sizeof cnt);
	REP(i,4)
	{
		REP(j,4)
		{
			cnt[i] += (board[i][j] == c || board[i][j] == 'T');
			cnt[4+j] += (board[i][j] == c || board[i][j] == 'T');
		}
		cnt[8] += (board[i][3-i] == c || board[i][3-i] == 'T');
		cnt[9] += (board[i][i] == c || board[i][i] == 'T');
	}
	return find(cnt, cnt+10, 4) != cnt+10;
}

bool full() {
	REP(i,4) REP(j,4) if(board[i][j] == '.') return false;
	return true;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		REP(i,4) scanf("%s", board[i]);
		if(won('X')) printf("X won\n");
		else if(won('O')) printf("O won\n");
		else if(full()) printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}

