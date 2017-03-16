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
int out[1000];
vector<int> in[1000];
int vis[1000];

int solve(int x, int p) {
	int r=1;
	for (int y : in[x]) if (y!=p) {
		r=max(r,1+solve(y,x));
	}
	return r;
}

int main() {
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		cerr << test << endl;
		printf("Case #%d: ",test);
		scanf("%d",&n);
		REP (i,n) in[i].clear();
		REP (i,n) {
			scanf("%d",&out[i]);
			out[i]--;
			in[out[i]].push_back(i);
		}
		// circle
		int circ=0;
		REP (i,n) {
			INIT(vis,0);
			vis[i]=1;
			int j=out[i],st=1;
			while (!vis[j]) {
				vis[j]=1;
				j=out[j];
				st++;
			}
			if (j==i) circ=max(circ,st);
		}
		// chains
		int ch=0;
		REP (i,n) {
			int j=out[i];
			if (i<j && out[j]==i) {
				ch+=solve(i,j);
				ch+=solve(j,i);
			}
		}
		printf("%d\n",max(circ,ch));
	}
	return 0;
}
