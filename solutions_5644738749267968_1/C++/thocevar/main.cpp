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
#define PRESENT(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) for (int i=(a);i>=(b);i--)
#define INIT(a,v) memset(a,v,sizeof(a))
#define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int n;
int a[1001],b[1001];

int war() {
	sort(a,a+n);
	set<int> sb(b,b+n);
	int sc=0;
	REP (i,n) {
		auto it = sb.lower_bound(a[i]);
		if (it==sb.end()) {
			sc++;
			sb.erase(sb.begin());
		} else {
			sb.erase(it);
		}
	}
	return sc;
}

int f[1001][1001];

int dwar() {
	sort(a,a+n);
	sort(b,b+n);
	FOR (k,0,n) f[n][k]=0;
	for (int i=n-1;i>=0;i--) {
		FOR (k,0,i) {
			f[i][k]=0;
			// force low
			if (b[k]<a[i]) {
				f[i][k]=max(f[i][k],f[i+1][k+1]+1);
			}
			// force high
			int sc=b[n-1-(i-k)]<a[i];
			f[i][k]=max(f[i][k],f[i+1][k]+sc);
		}
	}
	return f[0][0];
}

int main() {
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	//freopen("D.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		fprintf(stderr,"%d/%d\n",test,tests);
		printf("Case #%d: ",test);
		scanf("%d",&n);
		double lf;
		REP (i,n) {
			scanf("%lf",&lf);
			a[i]=round(lf*1e5);
		}
		REP (i,n) {
			scanf("%lf",&lf);
			b[i]=round(lf*1e5);
		}
		int y=dwar();
		int z=war();
		printf("%d %d\n",y,z);
	}
	return 0;
}
