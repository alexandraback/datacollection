/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1
#define INF				0x3f3f3f3f
#define mset(a, val)	memset(a, (val), sizeof(a))

// #define LOCAL_DEBUG

typedef struct {
	int v, nxt;
} edge_t;

const int maxn = 1005;
const int maxv = maxn;
const int maxe = maxv * 2;
int head[maxv], l;
edge_t E[maxe];
int bff[maxn];
bool visit[maxv];
int mx[maxv], mx_[maxv];
int n;
int ans, rt;
bool flag;

inline void init() {
	l = 0;
	memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
	E[l].v = v;
	E[l].nxt = head[u];
	head[u] = l++;
}

void dfs(int u, int dep) {
	int k, v;
	
	mx[u] = mx_[u] = 0;
	visit[u] = true;
	if (bff[rt] == u)
		ans = max(ans, dep);
	for (k=head[u]; k!=-1; k=E[k].nxt) {
		v = E[k].v;
		if (visit[v])
			continue;
		dfs(v, dep+1);
		if (mx[v]+1 > mx[u]) {
			mx_[u] = mx[u];
			mx[u] = mx[v]+1;
		} else if (mx[v]+1 > mx_[u]) {
			mx_[u] = mx[v]+1;
		}
	}
	// visit[u] = false;
}

void solve() {
	
	ans = 1;
	rep(u, 1, n+1) {		
		init();
		rep(j, 1, n+1) {
			addEdge(bff[j], j);
		}
		memset(visit, false, sizeof(visit));
		rt = u;
		dfs(u, 1);
		// if (mx_[u] > 0)
			// ans = max(ans, mx[u]+1+mx_[u]);
		for (int k=head[u]; k!=-1; k=E[k].nxt) {
			int v = E[k].v;
			if (bff[u] == v) {
				if (mx[v]+1 == mx[u])
					ans = max(ans, mx[v]+2+mx_[u]);
				else
					ans = max(ans, mx[v]+2+mx[u]);
			}
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef LOCAL_DEBUG
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	
	int t;
	
	cin >> t;
	rep(tt, 1, t+1) {
		cin >> n;
		rep(i, 1, n+1) {
			cin >> bff[i];
			// --bff[i];
		}
		printf("Case #%d: ", tt);
		solve();
	}
	
	#ifdef LOCAL_DEBUG
		printf("time = %ldms.\n", clock());
	#endif
	
	return 0;
}
