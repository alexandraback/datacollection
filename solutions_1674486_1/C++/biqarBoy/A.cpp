#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x ) for( i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

//typedef long long i64;
//typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1<<28);
const int MAX = 1005;

vector< int > G[MAX];
int flg[MAX], stk[MAX], idx, fa[MAX];
int n;
bool ff;

void dfs1(int u) {
	int i, j, k, v, sz;
	flg[u] = 1;
	sz = G[u].size();

	for(i=0; i<sz; i++) {
		v = G[u][i];
		if(!flg[v]) {
			dfs1(v);
		}
	}
	stk[idx++] = u;
}

void dfs2(int u) {
	int i, j, k, v, sz;
	flg[u] = 2;
	fa[u] = 1;
	sz = G[u].size();

	for(i=0; i<sz; i++) {
		v = G[u][i];
		if(fa[v] == 0) {
			dfs2(v);
		}
		else if(fa[v] == 1) {
			ff = true;
			return;
		}
	}
}

int main() {
	//freopen("A-large.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k;
	int test, t = 0, kase=0;
	int sz, u, v;

	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i=1; i<=n; i++) G[i].clear();
		for(i=1; i<=n; i++) {
			scanf("%d", &sz);
			for(j=0; j<sz; j++) {
				scanf("%d", &k);
				G[i].push_back(k);
			}
		}

		memset(flg, 0, sizeof(flg));
		idx = 0;
		for(i=1; i<=n; i++) {
			if(!flg[i]) {
				dfs1(i);
			}
		}

		ff = false;
		for(i=idx-1; i>=0; i--) {
			if(flg[stk[i]] == 1) {
				memset(fa, 0, sizeof(fa));
				dfs2(stk[i]);
			}
			if(ff) break;
		}
		if(!ff) printf("Case #%d: No\n", ++t);
		else printf("Case #%d: Yes\n", ++t);
	}
	return 0;
}
