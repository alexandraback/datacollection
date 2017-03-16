#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1ll<<60)
#define MAXV 40000
#define MAXE 100000

using namespace std;
typedef long long ll;
int flag[MAXV], head[MAXV], size, edgeID[MAXE];
int que[MAXV + 10], front, rear, pre[MAXV];
ll dist[MAXV], maxFlow[MAXV];

struct Edge {
	int v, next, opp;     //边上的另一个顶点, 下一条边, 反向边 
	ll cost, cap, f;      //花费、容量、流量 
	Edge(){}
	Edge(int _v, ll _cost, ll _cap, ll _f, int _next, int _opp):
		v(_v), cost(_cost), cap(_cap), f(_f), next(_next), opp(_opp){}
}edge[MAXE*2];

void init() {
	size = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, ll cap, ll cost, ll f = 0) {
	edge[size] = Edge(v, cost, cap, f, head[u], size + 1);
	edgeID[size] = u;
	head[u] = size++;
	edge[size] = Edge(u, -cost, 0, f, head[v], size - 1);
	edgeID[size] = v;
	head[v] = size++;
}

int SPFA(int S, int T) {      //找花费最小的一条路 
	int i, u, v;
	front = rear = 0;
	memset(flag, 0, sizeof(flag));              
	memset(pre, -1, sizeof(pre));               
	for(int i = 0;i < MAXV; ++i) dist[i] = INF;
	dist[S] = 0;	                                                  
	flag[S] = 1;
	maxFlow[S] = INF;
	que[rear++] = S;
	while (front != rear) {
		u = que[front++];
		if(front >= MAXV) front = 0;
		flag[u] = 0;
		for(i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].v;
			if (edge[i].cap > edge[i].f && dist[v] > dist[u] + edge[i].cost){
				dist[v] = dist[u] + edge[i].cost;
				maxFlow[v] = min(edge[i].cap - edge[i].f, maxFlow[u]);
				pre[v] = i;          //记录前驱在edge中的下标
				if (!flag[v]) {
					que[rear++] = v;
					if (rear >= MAXV) rear = 0;
					flag[v] = 1;
				}
			}
		}
	}
	if (dist[T] == INF) return 0;
	else return 1;
}

ll MFMC(int S, int T) {
	ll sumCost, sumFlow;
	int k;
	sumCost = sumFlow = 0;
	while (SPFA(S, T)) {
		k = T;
		while (pre[k] >= 0) {
			edge[pre[k]].f += maxFlow[T];
			edge[edge[pre[k]].opp].f = -edge[pre[k]].f;
			k = edgeID[pre[k]];
		}
		sumFlow += maxFlow[T];
		sumCost += dist[T] * maxFlow[T];
	}
	return sumCost;
}
ll E, R, N;
ll v[10010];
int main()
{
	int src, sink;
	int cas;
	scanf("%d",&cas);
	for(int it = 1;it <= cas; ++it){
		scanf("%lld%lld%lld",&E,&R,&N);
		init();
		for(int i = 1;i <= N; ++i) scanf("%lld",&v[i]);
		src = 0; sink = 2*N;
		for(int i = 1;i < N; ++i){
			add_edge(i, i + N, E, 0);
			add_edge(i + N, i + 1, E, 0);
		}
		add_edge(src, 1, E, 0);
		for(int i = 1;i < N; ++i) add_edge(src, i + N, R, 0);

		for(int i = 1;i <= N; ++i) add_edge(i, sink, E, -v[i]);
		ll ans = MFMC(src, sink);
		printf("Case #%d: %lld\n",it,-ans);
	}
	


}
