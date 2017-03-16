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
int n;
vector<vector<int> > sol;

void solve(vector<vector<int> > g, vector<vector<int> > t, int k=0) {
	if (!sol.empty()) return;
	//printf("k=%d\n",k);
	if (k==n) {
		/*REP (i,n) {
			REP (j,n) {
				printf("%d ",t[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		REP (i,n) {
			vector<int> v;
			REP (j,n) v.push_back(t[i][j]);
			sol.push_back(v);
			v.clear();
			REP (j,n) v.push_back(t[j][i]);
			sol.push_back(v);
		}
	} else {
		int m=9999;
		REP (i,g.size()) {
			if (g[i][k]<m) m=g[i][k];
		}
		vector<vector<int> > gs;
		REP (i,g.size()) {
			if (g[i][k]==m) gs.push_back(g[i]);
		}
		if (gs.size()==1) gs.push_back(vector<int>(n,0));

		/*REP (i,n) printf("%d,",gs[0][i]); printf("\n");
		REP (i,n) printf("%d,",gs[1][i]); printf("\n");
		REP (i,n) {
			REP (j,n) {
				printf("%d ",t[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		REP (it,k==0?1:2) {
			int ok=1;
			for (int i=0;i<n;i++) if (gs[0][i]!=0) {
				if (i<k) {
					if (t[k][i]!=0 && gs[0][i]!=t[k][i]) { ok=0; break; }
				} else {
					if (k>0 && t[k-1][i]!=0 && gs[0][i]<=t[k-1][i]) { ok=0; break; }
				}
			}
			for (int i=0;i<n;i++) if (gs[1][i]!=0) {
				if (i<k) {
					if (t[i][k]!=0 && gs[1][i]!=t[i][k]) { ok=0; break; }
				} else {
					if (k>0 && t[i][k-1]!=0 && gs[1][i]<=t[i][k-1]) { ok=0; break; }
				}
			}
			if (ok) {
				vector<vector<int> > u=t;
				for (int i=0;i<n;i++) {
					if (gs[0][i]!=0) u[k][i]=gs[0][i];
					if (gs[1][i]!=0) u[i][k]=gs[1][i];
				}
				vector<vector<int> > h;
				REP (i,g.size()) {
					if (g[i]!=gs[0] && g[i]!=gs[1]) h.push_back(g[i]);
				}
				solve(h,u,k+1);
			}
			swap(gs[0],gs[1]);
		}
	}
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		cerr << test << endl;
		printf("Case #%d: ",test);
		cin >> n;
		vector<vector<int> > g, t;
		REP (i,n) {
			t.push_back(vector<int>(n,0));
		}
		REP (i,2*n-1) {
			vector<int> r;
			REP (j,n) {
				int x;
				cin >> x;
				r.push_back(x);
			}
			g.push_back(r);
		}
		sol.clear();
		solve(g,t,0);
		REP (i,2*n-1) {
			sol.erase(find(ALL(sol),g[i]));
		}
		REP (i,n) {
			if (i!=0) printf(" ");
			printf("%d",sol[0][i]);
		}
		printf("\n");
	}
	return 0;
}
