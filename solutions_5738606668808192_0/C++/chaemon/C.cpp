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

vector<string> generate(int N,int J){
	int n=N/2;
	int m=n-2;
	int B=(1<<m);
	vector<string> vs;
	REP(b,B){
		string s="";
		s+="11";
		int b2=b;
		REP(i,m){
			if(b&(1<<i))s+="11";
			else s+="00";
		}
		s+="11";
		vs.push_back(s);
		if(vs.size()==J)break;
	}
	return vs;
}

void main2(){
	int N,J;
	cin>>N>>J;
	vector<string> vs = generate(N,J);
	vector<int> divs;
	for(int b=2;b<=10;b++)divs.push_back(b+1);
	assert(vs.size()==J);
	REP(i,vs.size()){
		cout<<vs[i];
		REP(i,divs.size()){
			cout<<" "<<divs[i];
		}
		cout<<endl;
	}
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<":"<<endl;
		main2();
	}
	return 0;
}
//}}}
