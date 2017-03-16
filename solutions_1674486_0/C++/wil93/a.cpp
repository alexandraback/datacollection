#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fs first
#define sc second
#define sz(x) (int((x).size()))
#define all(x) ((x).begin()),((x).end())
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define fab(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fba(i,b,a) for(int (i)=(b);(i)>=(a);(i)--)
#define MAX(a,x) a=max(a,x)
#define MIN(a,x) a=min(a,x)

using namespace std;

const double eps = 1e-10, inf = 1e10;
typedef long long ll;

#define MAXN 1010

int n, was[MAXN], mx[MAXN][MAXN], pt[MAXN][MAXN];
//vector<int> adj[MAXN];

/*bool bfs(int u)
{
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (was[u]) return true;
		was[u] = 1;
		rep(i, sz(adj[u])) {
			int v = adj[u][i];
			q.push(v);
		}
	}
	return false;
}*/

void solve(int test)
{
	printf("Case #%d: ", test);
	
	memset(mx, 0, sizeof mx);
	memset(pt, 0, sizeof pt);

	scanf("%d", &n);
	rep(i, n) {
		int mi, xx;
		scanf("%d", &mi);
		while (mi--) {
			scanf("%d", &xx);
			//adj[i].pb(xx-1);
			mx[i][xx-1] = 1;
		}
	}
	
	/*rep(i, n) {
		memset(was, 0, sizeof was);
		if (bfs(i)) {
			printf("Yes\n");
			return;
		}
	}*/
	
	rep(k, n)
	rep(i, n)
	rep(j, n) {
		mx[i][j] += mx[i][k] * mx[k][j];
		
		if (mx[i][j] > 1) { printf("Yes\n"); return; }
	}
	
	printf("No\n");
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	scanf("%d", &t);
	rep(i,t) solve(i+1);
	return 0;
}
