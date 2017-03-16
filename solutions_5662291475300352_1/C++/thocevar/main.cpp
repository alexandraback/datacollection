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
int hikers[10];

struct hiker {
	int64 d,m;
};

bool operator<(hiker h1, hiker h2) {
	if (h1.d==h2.d) return h1.m>h2.m;
	else return h1.d<h2.d;
}

int main() {
	//freopen("test.in","r",stdin);
	freopen("C-small-2-attempt0.in","r",stdin);
	freopen("C-small-2-attempt0.out","wb",stdout);

	cin >> tests;
	FOR (test,1,tests) {
		cin >> n;
		vector<hiker> hs;
		REP (i,n) {
			int d,h,m;
			scanf("%d %d %d",&d,&h,&m);
			REP (j,h) hs.push_back({d,m+j});
		}
		sort(ALL(hs));
		n=hs.size();
		int64 r=n;
		REP (f,n) {
			int64 tf=(360-hs[f].d)*hs[f].m;
			int64 rf=0;
			REP (i,n) if (i!=f) {
				int64 ti=(360-hs[i].d)*hs[i].m;
				int64 t=max(tf-ti,0LL);
				int64 li=t/(hs[i].m*360);
				rf+=li;
				if (i<f) {
					if (ti>tf) rf++;
				} else if (f<i) {
					if (ti>tf) rf++;
				}
			}
			r=min(r,rf);
		}
		printf("Case #%d: %I64d\n",test,r);
	}
	return 0;
}
