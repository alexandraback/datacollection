#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

struct edge {
    int f, t;
    int cap, cost;
} E[1000005];
vector<int> adj[1111];
priority_queue<pii> q;
int dis[555],path[1111];
int S,T,N;
// S = start, T = end;
// E[x]'s back edge = E[x^1]
 
void add_edge(int u, int v, int cap, int cost) {
    E[N].f = u, E[N].t = v, E[N].cap = cap, E[N].cost = cost;
    adj[u].push_back(N), N++;
    E[N].f = v, E[N].t = u, E[N].cap = 0, E[N].cost = -cost;
    adj[v].push_back(N), N++;
}
 
bool find() {
    while(q.size()) q.pop();
    for(int i=S;i<=T;++i) dis[i] = (1<<30), path[i] = -1;
    path[S] = -2, dis[S] = 0, q.push(mp(-0,S));
 
    while(q.size()) {
        int u = q.top().second;
        q.pop();
        for(int i=0;i<adj[u].size();++i) {
            int v = E[adj[u][i]].t;
            int w = E[adj[u][i]].cost;
            if(E[adj[u][i]].cap > 0 && dis[v] > dis[u] + w) {
                path[v] = adj[u][i], dis[v] = dis[u] + w;
                q.push(mp(-dis[v],v));
            }
        }
    } return dis[T] != (1<<30);
}
 
int mcmf(int &cost) {
    int ret = 0; cost = 0;
    while(find()) {
        int bot = (1<<30), u = T;
        while(path[u] >= 0) {
            bot = min(bot, E[path[u]].cap);
            u = E[path[u]].f;
        } u = T, cost += bot * dis[T];
        while(path[u] >= 0) {
            E[path[u]  ].cap -= bot;
            E[path[u]^1].cap += bot;
            u = E[path[u]].f;
        } ret += bot;
    } return ret;
}

int Ts,n;
double a[1005],b[1005];

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		printf("Case #%d: ", cs);

		bool ck_b[1005];
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%lf",a+i);
		for(int i=0;i<n;++i) scanf("%lf",b+i);
		sort(a,a+n), sort(b,b+n);

		S = 0, T = 2 * n + 1, N = 0;

		for(int i=0;i<n;++i) {
			add_edge(S,i+1,1,0);
			add_edge(i+1+n,T,1,0);
			for(int j=0;j<n;++j) {
				if(a[i] < b[j]) {
					add_edge(i+1,j+1+n,1, 0);
				}
				else {
					add_edge(i+1,j+1+n,1,-1);
				}
			}
		}

		int cost, sum = 0;
		mcmf(cost);
		
		memset(ck_b,0,sizeof(ck_b));
		for(int i=0;i<n;++i) {
			bool ok = 0;
			for(int j=0;j<n;++j) if(!ck_b[j] && b[j] > a[i]) {
				ck_b[j] = 1, ok = 1;
				break;
			} sum += !ok;
		}

		printf("%d %d\n",-cost,sum);

		for(int i=0;i<=T;++i) adj[i].clear();
	}
}