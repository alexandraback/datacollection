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
int k,c,s;

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (t,1,tests) {
		cin >> k >> c >> s;
		printf("Case #%d:",t);
		int64 p=1;
		REP (i,c-1) p*=k;
		REP (i,k) {
			printf(" %I64d",1+i*p);
		}
		printf("\n");
	}
	return 0;
}

