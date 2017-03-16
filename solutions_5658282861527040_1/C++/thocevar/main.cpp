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
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) for (int i=(a);i>=(b);i--)
#define INIT(a,v) memset(a,v,sizeof(a))
#define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int a,b,k;
int64 f[30][2][2][2];

int64 solve(int i, int la, int lb, int lk) {
	if (i<0) {
		return (la && lb && lk);
	}
	int64 &r = f[i][la][lb][lk];
	if (r!=-1) return r;
	r=0;
	int ai = (a&(1<<i))!=0;
	int bi = (b&(1<<i))!=0;
	int ki = (k&(1<<i))!=0;
	FOR (x,0,1) FOR (y,0,1) {
		int z=x&y;
		int ok=1;
		if (x && !la && !ai) ok=0;
		if (y && !lb && !bi) ok=0;
		if (z && !lk && !ki) ok=0;
		if (ok) {
			r += solve(i-1, la || (x<ai), lb || (y<bi), lk || (z<ki));
		}
	}
	return r;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int tests;
	cin >> tests;
	FOR (test,1,tests) {
		//fprintf(stderr,"%d/%d\n",test,tests);
		scanf("%d %d %d",&a,&b,&k);
		INIT(f,-1);
		int64 st = solve(29,0,0,0);
		printf("Case #%d: %I64d\n",test,st);
	}
	return 0;
}
