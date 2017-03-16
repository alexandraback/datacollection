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

#define MAX 1000
int64 a[MAX];
int64 c[MAX];
int64 Min(int64 a,int64 b) {
	return a<b?a:b;
}

int64 solve() {
	
	int64 C,D,V,k;
	sl(C);sl(D);sl(V);
	REP(i,MAX) a[i]=0;
	REP(i,D) {
		sl(k);
		
		FORD(j,V,1) {
			if(a[j]==1) {
				if(j+k<MAX)
					a[j+k]=1;
			}
		}
		a[k]=1;
	}
	int64 c=0;
	FOR(i,1,V) {
		if(a[i]==0) {
			c++;
			FORD(j,V,1) {
				if(a[j]==1) {
					if(j+i<MAX)
						a[j+i]=1;
				}
			}
			a[i]=1;
		}
	}
		return c;

}
int main() {
#if SMALL
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
#endif
#if LARGE
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
#endif
	int T;
	si(T);

	FOR(i,1,T) {
		printf("Case #%d: ", i);
		
		int64 L = solve();
		printf("%lld\n",L);
	}
	return 0;
}
