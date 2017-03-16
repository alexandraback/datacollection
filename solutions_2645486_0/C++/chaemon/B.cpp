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

Int E,R,N;
vector<Int> v;
int dp[10][10];//energy, day

int calc(int e,int i){
	e=min(e,(int)E);
	if(dp[e][i]>=0)return dp[e][i];
	if(i==N)return 0;
	int ans=0;
	for(int j=0;j<=e;j++){
		ans=max(ans,calc(e-j+R,i+1)+(int)v[i]*j);
	}
//	cout<<e<<" "<<i<<" "<<ans<<endl;
	return dp[e][i]=ans;
}

void main2(){
	memset(dp,-1,sizeof(dp));
	cin>>E>>R>>N;
	v.clear();
	REP(i,N){
		Int a;
		cin>>a;
		v.push_back(a);
	}
	cout<<calc(E,0)<<endl;
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
