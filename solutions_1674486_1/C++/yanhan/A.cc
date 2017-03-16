#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAXN 1000
#define INF 1000000000
typedef vector<int> vi;
int src, sink;

struct Edge {
	int x; int y; int cap; int flow;
	Edge() { x = y = cap = flow = 0; }
	Edge(int _x, int _y, int _cap): x(_x), y(_y), cap(_cap), flow(0) {}
};

vector<Edge> edges;
vector<vi> adj;
int out[MAXN+5];
int in[MAXN+5];
int TC, N, g, tmp;
#define ADDEDGE(xx, yy, cc) do{\
	adj[xx].push_back(edges.size());\
	edges.push_back(Edge(xx,yy,cc));\
	adj[yy].push_back(edges.size());\
	edges.push_back(Edge(yy,xx,0));\
}while(0)

#define RESET() do{\
	edges.clear();\
	for (int ik = 0; ik <= MAXN+5; ik++)\
		adj[ik].clear();\
	memset(out, 0, sizeof out);\
	memset(in, 0, sizeof in);\
}while(0)

int par[MAXN+10];

int main(int argc, char *argv[])
{
	int v, flow, len, mf, can;
	for (int i = 0; i <= MAXN+10; i++) {
		vi vec;
		adj.push_back(vec);
	}
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		RESET();
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &g);
			for (int k = 0; k < g; k++) {
				scanf("%d", &tmp);
				ADDEDGE(i, tmp, 1);
				out[i]++;
				in[tmp]++;
			}
		}
		can = 0;
		for (int i = 1; i <= N && !can; i++) {
			for (int k = 1; k <= N && !can; k++) {
				if (i == k || out[i] < 2 || in[k] < 2) continue;
				src = i;
				sink = k;
				mf = 0;
				// reset
				len = edges.size();
				for (int m = 0; m < len; m++) {
					edges[m].flow = 0;
				}
				while (1) {
					queue<int> q;
					q.push(src);
					memset(par, -1, sizeof par);
					while (!q.empty()) {
						v = q.front(); q.pop();
						if (v == sink)
							break;
						len = adj[v].size();
						for (int m = 0; m < len; m++) {
							Edge &e = edges[adj[v][m]];
							if (par[e.y] == -1 && e.cap - e.flow > 0) {
								par[e.y] = adj[v][m];
								q.push(e.y);
							}
						}
					}
					if (par[sink] == -1)
						break;
					flow = INF;
					for (int x = sink; x != src; x = edges[par[x]].x)
						flow = min(flow, edges[par[x]].cap - edges[par[x]].flow);
					for (int x = sink; x != src; x = edges[par[x]].x) {
						edges[par[x]].flow += flow;
						edges[par[x]^1].flow -= flow;
					}
					mf += flow;
				}
				if (mf > 1) {
					can = 1;
					break;
				}
			}
		}
		printf("Case #%d: ", t);
		if (can)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
