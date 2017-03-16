#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long LL;
#define FOR(x, b, e) for (int x = (b); x <= (e); ++x)
#define FORD(x, b, e) for (int x = (b); x >= (e); --x)
#define REP(x, n) for (int x = 0; x < (n); ++x)
#define VAR(v, n) typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int) (x).size())
#define EACH(i, c) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define REACH(i, c) for (VAR(i,(c).rbegin()); i != (c).rend(); ++i)
#define UNIQUE(v) do { sort(ALL(v)); (v).resize(unique(ALL(v)) - (v).begin()); } while (0)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define skip continue
const int INF = 1000000001;

#define GET(x)			(scanf("%d", &(x)) == 1)
#define GET2(x, y)		(scanf("%d %d", &(x), &(y)) == 2)
#define GET3(x, y, z)	(scanf("%d %d %d", &(x), &(y), &(z)) == 3)
#define GETS(x)			(scanf("%s", (x)) == 1)
#define DGET(x)			int x; GET(x);

const int N = 1001;
vector<int> G[N];

int vis[N];
int BFS_ID;

bool bfs(int src)
{
	vector<int> q;
	q.reserve(N);
	
	vis[src] = ++BFS_ID;
	q.PB(src);
	
	EACH (v, q) {
		EACH (u, G[*v]) {
			if (vis[*u] == BFS_ID) {
				return true;
			}
			vis[*u] = BFS_ID;
			q.PB(*u);
		}
	}
	return false;
}

int main()
{
	DGET(t);
	FOR (tt, 1, t) {
		DGET(n);
		
		FOR (i, 1, n) {
			DGET(m);
			G[i].resize(m);
			REP (mm, m) {
				GET(G[i][mm]);
			}
		}
		bool ok = true;
		FOR (i, 1, n) {
			if (bfs(i)) {
				ok = false;
				break;
			}
		}
		printf("Case #%d: %s", tt, ((!ok) ? "Yes\n" : "No\n"));
	}
}
