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

int n,m;
vector<pair<string,int> > neigh[51];
string path;
string code[51];

void solve(int x, vector<int> v, vector<int> s, string p) {
	p+=code[x];
	v.push_back(x);
	s.push_back(x);
	//if (path!="" && p>path) return;
	if (v.size()==n) {
		//printf("? %s\n",p.c_str());
		if (path=="" || p<path) path=p;
		return;
	}
	while (!s.empty()) {
		int y = s.back();
		for (auto cz : neigh[y]) {
			string c=cz.first;
			int z=cz.second;
			if (!IN(z,v)) {
				solve(z,v,s,p);
			}
		}
		s.pop_back();
	}
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int tests;
	cin >> tests;
	FOR (test,1,tests) {
		fprintf(stderr,"%d/%d\n",test,tests);
		cin >> n >> m;
		REP (i,n) {
			neigh[i].clear();
			cin >> code[i];
		}
		REP (i,m) {
			int a,b;
			scanf("%d %d",&a,&b);
			a--; b--;
			neigh[a].push_back({code[b],b});
			neigh[b].push_back({code[a],a});
		}
		REP (i,n) {
			sort(ALL(neigh[i]));
		}
		path="";
		REP (i,n) {
			solve(i,{},{},"");
		}
		printf("Case #%d: %s\n",test,path.c_str());
	}
	return 0;
}
