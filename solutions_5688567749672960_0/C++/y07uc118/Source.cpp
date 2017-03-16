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

int64 M[1000010];
int64 Min(int64 a,int64 b) {
	return a<b?a:b;
}

int64 Reverse(int64 n) {
	int64 R=0;
	while(n>0) {
		R = R*(10)+(n%10);
		n = n/10;
	}
	return R;
}

void init() {
	for (int64 i=1;i<MAX;i++) {
		if(i<=20) M[i]=i;
		else {
			int64 R = Reverse(i);
			M[i] = 1+M[i-1];
			if(R<i && i==Reverse(R)) M[i]=Min(M[i],M[R]+1);
		}
	}
}

int64 solve(int N) {

	return M[N];
}
int main() {
#if SMALL
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
#endif
#if LARGE
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
#endif
	int T;
	si(T);
	init();
	FOR(i,1,T) {
		printf("Case #%d: ", i);
		int64 N;
		sl(N);
		int64 L = solve(N);
		printf("%lld\n",L);
	}
	return 0;
}
