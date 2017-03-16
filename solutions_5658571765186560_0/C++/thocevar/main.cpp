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
int x,r,c;

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		printf("Case #%d: ",test);
		cin >> x >> r >> c;
		if (r>c) swap(r,c);
		int bad=0;
		if ((r*c)%x!=0) {
			bad=1;
		} else {
			if (x==3) {
				if (r==1 && c==3) bad=1;
			}
			if (x==4) {
				if (r==1 && c==4) bad=1;
				if (r==2 && c==2) bad=1;
				if (r==2 && c==4) bad=1;
			}
		}
		if (bad) printf("RICHARD\n");
		else printf("GABRIEL\n");
	}
	return 0;
}
