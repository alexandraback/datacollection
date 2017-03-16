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

#include<bitset>

int C,D,V;
int currency[110];
uint dp[2];
bool exist[32];
uint base, VB;

void make_base(){
	dp[0]=(1u<<0);
	REP(i,D){
		int from = i%2, to = (i+1)%2;
		dp[to]=(dp[from]|(dp[from]<<currency[i]));
	}
	base = dp[D%2];
	VB = (1<<(V+1))-1;

	/*
	for(int i=0;i<=V;i++){
		int b = (base&(1u<<i))?1:0;
		cout<<i<<": "<<b<<endl;
	}
	*/
}

bool is_valid(const vector<int> &v){
	dp[0]=base;
	REP(i,v.size()){
		int from = i%2, to = (i+1)%2;
		dp[to]=(dp[from]|(dp[from]<<v[i]));
	}
	int from = (v.size())%2;
	for(int i=0;i<=V;i++){
		if((dp[from]&(1u<<i))==0){
			return false;
		}
	}
	return true;
}

int result;

void find(uint b,int prev, int level=0){
	if((b&VB)==VB){
		result = min(result,level);
	}
	for(int c=prev+1;c<=V;c++){
		if(exist[c])continue;
		if(level<4){
			find(b|(b<<c),c,level+1);
		}
	}
}

void main2(){
	cin>>C>>D>>V;
	REP(i,D){
		cin>>currency[i];
	}
	make_base();
	memset(exist,false,sizeof(exist));
	REP(i,D)exist[currency[i]]=true;
	result = 5;
	find(base,0);
	cout<<result<<endl;
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
