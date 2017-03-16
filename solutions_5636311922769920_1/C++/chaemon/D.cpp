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

int K,C,S;

/*
void main2(){
	cin>>K>>C>>S;
	assert(K==S);
	for(int i=1;i<=S;i++){
		cout<<" "<<i;
	}
	cout<<endl;
}
*/

void main2(){
	cin>>K>>C>>S;
	if(K>C*S){
		cout<<" IMPOSSIBLE"<<endl;
		return;
	}
	vector<vector<int> > vv;
	int ct=0;
	REP(i,S){
		vector<int> v;
		REP(j,C){
			if(ct<K)v.push_back(ct);
			else v.push_back(0);
			ct++;
		}
		vv.push_back(v);
		if(ct>=K)break;
	}
	cerr<<"nya"<<endl;
	REP(i,vv.size()){
		Int ans=0;
		REP(j,vv[i].size()){
			cerr<<vv[i][j]<<" ";
			ans*=K;
			ans+=vv[i][j];
		}
		cerr<<endl;
		cout<<" "<<ans+1;
	}
	cout<<endl;
}


// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<":";
		main2();
	}
	return 0;
}
//}}}
