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

#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
// }}}

vector<long long> x;
const int N=10000000;

bool isPalin(long long n){
	vector<int> v;
	while(n>0)v.push_back(n%10),n/=10;
	int i=0,j=v.size()-1;
	for(;i<j;i++,j--){
		if(v[i]!=v[j])return false;
	}
	return true;
}

void init(){
	for(long long u=1;u<=N;u++){
		long long s=u*u;
		if(isPalin(u) and isPalin(s)){
			x.push_back(s);
//			cout<<s<<" "<<u<<endl;
		}
	}
//	cout<<x<<endl;
//	assert(false);
}

void main2(){
	long long A,B;
	cin>>A>>B;
	A--;
	cout<<distance(x.begin(),upper_bound(ALL(x),B))-distance(x.begin(),upper_bound(ALL(x),A))<<endl;
}

//{{{ main function
int main() {
	init();
	int T;scanf("%d", &T);
	REP(ct, T){
		printf("Case #%d: ",ct+1);
		main2();
	}
	return 0;
}
//}}}
