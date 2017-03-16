#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 10002;

//const int MAXN = 500;
const int MAXM = 40000;
const int INF = 0x3f3f3f3f;

struct MinCostMaxFlow {
#define RE(i) ((((i) - P) ^ 1) + P)
	struct Edge {
		int v, c, w; // endpoint, capacity, cost
		Edge* next;
		Edge(int v = 0, int c = 0, int w = 0, Edge* next = NULL)
			: v(v), c(c), w(w), next(next) {}
	};

	int n, x, S, T;
    ll maxflow;
	int psize; // memory pool index
	Edge P[MAXM * 2]; // memory pool for edges
	Edge* e[MAXN]; // edges

	bool spfa(ll& ret) {
		vector <bool> v(n, false);
		vector <ll> mind(n, INF);
		vector <int> c(n, 0);
		Edge* pre[MAXN];
		for (int i = 0; i < n; ++i) {
			pre[i] = NULL;
		}
		queue <int> q;
		q.push(S);
		mind[S] = 0;
		v[S] = true;
		c[S] = INF;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			v[t] = false;
			for (Edge* i = e[t]; i != NULL; i = i->next) {
				if (mind[t] + i->w < mind[x = i->v] && i->c != 0) {
					mind[x] = mind[t] + i->w;
					c[x] = min(c[t], i->c);
					pre[x] = RE(i);
					if (!v[x]) {
						q.push(x);
						v[x] = true;
					}
				}
			}
		}
		if (c[T] != 0 && mind[T] < 0) {
			maxflow += c[T];
			ret += c[T] * mind[T];
			for (int i = T; i != S; i = pre[i]->v) {
				pre[i]->c += c[T];
				RE(pre[i])->c -= c[T];
			}
			return true;
		}
		return false;
	}

	// calculate the min cost max flow
	// return the netcost, the max flow stored in maxflow
	// S and T should be different!
	ll flow(int _S, int _T) {
		ll ret = maxflow = 0;
		n = max(n, max(S = _S, T = _T)) + 1;
		while (spfa(ret));
		return ret;
	}
	
	// call this function first
	void init() {
		n = psize = 0;
		memset(e, 0, sizeof(e));
	}

	// add edges to the graph
	void addEdge(int u, int v, int c, int w) {
        //printf("add %d %d %d %d\n", u, v, c, w);
		P[psize] = Edge(v, c, w, e[u]);
		e[u] = &P[psize++];
		P[psize] = Edge(u, 0, -w, e[v]);
		e[v] = &P[psize++];
		n = max(n, max(u, v));
	}
} mcf;

int T, E, R, n;
int a[MAXN];
ll spend[MAXN];
ll fromRight[MAXN];

ll gao() {
    ll ret = 0;
    mcf.init();
    int source = n, sink = source + 1;
    for (int i = 0; i < n; ++i) {
        int t = i == n - 1 ? E : R;
        ret += (ll)a[i] * t;
        mcf.addEdge(source, i, t, 0);
        mcf.addEdge(i, sink, E, 0);
    }
    for (int i = 1; i < n; ++i) {
        mcf.addEdge(i, i - 1, E - R, a[i] - a[i - 1]);
    }
    ret += -mcf.flow(source, sink);
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d%d%d", &E, &R, &n);
        R = min(R, E);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        ll res = gao();
        printf("Case #%d: %lld\n", caseNum, res);
    }
    return 0;
}
