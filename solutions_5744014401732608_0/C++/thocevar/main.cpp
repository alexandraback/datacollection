#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define INIT(a,v) memset(a,v,sizeof(a))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef long long int64;
typedef pair<int64,int64> PII;

int tests;
int b;
int64 m;

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		//cerr << test << endl;
		printf("Case #%d: ",test);
		cin >> b >> m;
		if ((1LL<<(b-2))<m) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("POSSIBLE\n");
			printf("0");
			if (m==(1LL<<(b-2))) {
				REP (i,b-1) printf("1");
				printf("\n");
			} else {
				for (int i=b-3;i>=0;i--) {
					if (m&(1LL<<i)) printf("1");
					else printf("0");
				}
				printf("0\n");
			}
			FOR (i,2,b-1) {
				FOR (j,1,b) {
					if (j>i) printf("1");
					else printf("0");
				}
				printf("\n");
			}
			FOR (j,1,b) printf("0");
			printf("\n");
		}
	}
	return 0;
}
