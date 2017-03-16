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

void main2(){
	int R,N,M,K;
	cin>>R>>N>>M>>K;
	REP(i,R){
		bool found=false;
		vector<int> s;
		REP(j,K){
			int a;
			cin>>a;
			s.push_back(a);
		}
		int pr=1;
		REP(i,N)pr*=(M-1);
		REP(d,pr){
			int d2=d;
			vector<int> v;
			REP(j,N){
				v.push_back(d2%(M-1)+2);
				d2/=(M-1);
			}
			/*
			REP(j,v.size())cout<<v[j]<<" ";
			cout<<endl;
			*/
			set<int> prod;
			REP(b,1<<N){
				int p=1;
				REP(j,N){
					if(b&(1<<j))p*=v[j];
				}
				prod.insert(p);
			}
			bool valid=true;
			REP(j,K){
				if(!EXIST(s[j],prod)){
					valid=false;
				}
			}
			if(valid){
				REP(j,v.size())cout<<v[j];
				cout<<endl;
				found=true;
			}
			if(found)break;
		}
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
