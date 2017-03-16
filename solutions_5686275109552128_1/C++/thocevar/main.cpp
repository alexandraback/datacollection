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

typedef pair<int,int> PII;
typedef long long int64;

int tests;
int d, p[1000];

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		cin >> d;
		int mp=0;
		REP (i,d) {
			cin >> p[i];
			mp=max(mp,p[i]);
		}
		int s=mp*d;
		FOR (m,1,mp) {
			int r=m;
			REP (i,d) {
				if (p[i]%m==0) r+=p[i]/m-1;
				else r+=p[i]/m;
			}
			s=min(s,r);
		}
		printf("Case #%d: %d\n",test,s);
	}
	return 0;
}
