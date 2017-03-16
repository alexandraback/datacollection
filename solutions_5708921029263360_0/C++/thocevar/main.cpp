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
int n1,n2,n3,k;

map<vector<int>, int> f;
vector<vector<int> > best, sol;

void solve(int id=0, int st=0) {
	if (sol.size()+(n1*n2*n3-id)<=best.size()) return;
	if (id==n1*n2*n3) {
		if (sol.size()>best.size()) best=sol;
	} else {
		int l=id%n3+1;
		int j=(id/n3)%n2+1;
		int i=(id/n3/n2)+1;
		if (f[{i,j,0}]<k && f[{i,0,l}]<k && f[{0,j,l}]<k) {
			f[{i,j,0}]++; f[{i,0,l}]++; f[{0,j,l}]++;
			sol.push_back({i,j,l});
			solve(id+1, st+1);
			sol.pop_back();
			f[{i,j,0}]--; f[{i,0,l}]--; f[{0,j,l}]--;
		}
		solve(id+1, st);
	}
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		//cerr << test << endl;
		printf("Case #%d: ",test);
		cin >> n1 >> n2 >> n3 >> k;
		best.clear();
		solve();
		printf("%d\n",best.size());
		for (auto x : best) {
			printf("%d %d %d\n",x[0],x[1],x[2]);
		}
	}
	return 0;
}
