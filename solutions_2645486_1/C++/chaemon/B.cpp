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

int E,R,N;
vector<int> v,next_large;

void main2(){
	cin>>E>>R>>N;
	v.clear();
	next_large.assign(N,-1);
	REP(i,N){
		int a;
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<N;i++){
		next_large[i]=INF;
		for(int j=i+1;j<N;j++){
			if(v[i]<v[j]){
				next_large[i]=j;
				break;
			}
		}
	}
	int t=E;
	Int ans=0ll;
	for(int i=0;i<N;i++,t+=R){
		Int lb=E-R*(Int)(next_large[i]-i);
		lb=max(0ll,lb);
//		cerr<<t<<" "<<lb<<" "<<endl;
		if(t<=lb)continue;
		else{
			ans+=(t-lb)*(Int)v[i];
			t=lb;
		}
	}
//	cerr<<endl;
	cout<<ans<<endl;
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
