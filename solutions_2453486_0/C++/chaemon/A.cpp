// #includes {{{
#include <algorithm>
#include <numeric>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
// }}}

char c[10][10];

void main2(){
	REP(i,4)cin>>c[i];
	bool foundX=false,foundO=false;
	bool found;
	REP(i,4){
		found=true;
		REP(j,4)if(!(c[i][j]=='X' or c[i][j]=='T'))found=false;
		if(found)foundX=true;
		found=true;
		REP(j,4)if(!(c[i][j]=='O' or c[i][j]=='T'))found=false;
		if(found)foundO=true;
	}
	REP(j,4){
		found=true;
		REP(i,4)if(!(c[i][j]=='X' or c[i][j]=='T'))found=false;
		if(found)foundX=true;
		found=true;
		REP(i,4)if(!(c[i][j]=='O' or c[i][j]=='T'))found=false;
		if(found)foundO=true;
	}
	found=true;
	REP(i,4)if(!(c[i][i]=='X' or c[i][i]=='T'))found=false;
	if(found)foundX=true;

	found=true;
	REP(i,4)if(!(c[i][3-i]=='X' or c[i][3-i]=='T'))found=false;
	if(found)foundX=true;

	found=true;
	REP(i,4)if(!(c[i][i]=='O' or c[i][i]=='T'))found=false;
	if(found)foundO=true;

	found=true;
	REP(i,4)if(!(c[i][3-i]=='O' or c[i][3-i]=='T'))found=false;
	if(found)foundO=true;

	bool nc=false;
	REP(i,4)REP(j,4)if(c[i][j]=='.')nc=true;
	if(foundX){
		printf("X won\n");
	}else if(foundO){
		printf("O won\n");
	}else if(nc){
		printf("Game has not completed\n");
	}else{
		printf("Draw\n");
	}
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){
		printf("Case #%d: ",ct+1);
		main2();
	}
	return 0;
}
//}}}
