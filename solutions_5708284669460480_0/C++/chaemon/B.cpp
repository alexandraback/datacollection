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

int K,L,S;
char keyboard[110], target[110];

void main2(){
	cin>>K>>L>>S;
	cin>>keyboard>>target;
	map<char,int> kbs;
	REP(i,K)kbs[keyboard[i]]++;
	REP(i,L){
		if(not EXIST(target[i],kbs)){
			cout<<"0.0"<<endl;
			return;
		}
	}
	int a;
	if(S<L){
		a = 0;
	}else{
		int t=1;
		for(;;t++){
			bool valid = true;
			for(int j=t;j<L;j++){
				if(target[j]!=target[j-t])valid = false;
			}
			if(valid)break;
		}
		a = (S-L)/t+1;
	}
	rn b = 1.0;
	REP(i,L){
		rn rate = (rn)kbs[target[i]]/(rn)K;
		b *= rate;
//		cout<<"target: "<<target[i]<<endl;
//		cout<<"rate: "<<rate<<endl;
	}
	b*=(S-L+1);
	rn ans;
	ans = (rn)a-b;
	printf("%.10Lf\n",ans);
//	cerr<<a<<" "<<b<<endl;
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
