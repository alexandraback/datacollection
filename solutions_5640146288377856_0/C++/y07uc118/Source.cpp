#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<stack>
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include<cassert>
#include<vector>
#include<climits>
#include<set>


#define DEBUG 0
#define SMALL 1
#define LARGE 0

using namespace std;
#if DEBUG
#define LOG1(a) cerr << "value of " << #a << ":" << a << endl
#define LOG2(a,b) LOG1(a);LOG1(b)
#define LOG3(a,b,c) LOG2(a,b);LOG1(c)
#define LOG4(a,b,c,d) LOG2(a,b);LOG2(c,d)
#else
#define LOG1(a) 
#define LOG2(a,b) 
#define LOG3(a,b,c) 
#define LOG4(a,b,c,d) 
#endif

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a);

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()


typedef long long int64;
typedef unsigned long long uint64;

#define MAX 1000010

int64 Min(int64 a,int64 b) {
	return a<b?a:b;
}

int64 solve() {
	int64 R,C,W;
	sl(R);sl(C);sl(W);
	int64 ans = (R-1)*(C/W);
	ans += (W+(C/W)-1);
	if((C%W)!=0) ans+=1;
	return ans;
}
int main() {
#if SMALL
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
#endif
#if LARGE
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
#endif
	int T;
	si(T);
	//init();
	FOR(i,1,T) {
		printf("Case #%d: ", i);
		
		int64 L = solve();
		printf("%lld\n",L);
	}
	return 0;
}
