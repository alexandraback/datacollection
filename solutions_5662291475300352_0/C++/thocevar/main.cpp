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
int n;
int d[10],h[10],m[10];

int main() {
	//freopen("test.in","r",stdin);
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","wb",stdout);

	cin >> tests;
	FOR (test,1,tests) {
		cin >> n;
		vector<pair<int64,int64> > t;
		REP (i,n) {
			scanf("%d %d %d",&d[i],&h[i],&m[i]);
			REP (j,h[i]) t.push_back({d[i],m[i]});
		}
		sort(ALL(t));
		int r=t.size();
		if (t.size()==1) r=0;
		else if (t.size()==2) {
			int64 d0=t[0].first, m0=t[0].second;
			int64 d1=t[1].first, m1=t[1].second;
			if (m0>=m1) {
				if (m0*(360-d0)<m1*(360+360-d1)) r=0;
				else r=1;
			} else {
				if (m1*(360-d1)<m0*(360+360-d0)) r=0;
				else r=1;
			}
		}
		printf("Case #%d: %d\n",test,r);
	}
	return 0;
}
