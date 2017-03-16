// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
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

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

rn C,F,X;

rn calc(int k){
	rn ans=0.0L;
	rn val = 2.0L;
	for(int i=0;i<k;i++,val+=F){
		ans+=C/val;
	}
	ans+=X/val;
	return ans;
}

void main2(){
	cin>>C>>F>>X;
	rn kr = (F*X/C-2.0L)/F-1.0L;
	if(kr<1.0L){
		printf("%.10Lf\n",min(min(calc(0),calc(1)),calc(2)));
		return;
	}
	int kmin = max(0,(int)(kr-5.0L)), kmax = (int)(kr+5.0L);
	rn ans = 1e+20L;
	for(int i=kmin;i<=kmax;i++){
		ans=min(calc(i),ans);
	}
	printf("%.10Lf\n",ans);
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": ";
		main2();
	}
	return 0;
}
//}}}
