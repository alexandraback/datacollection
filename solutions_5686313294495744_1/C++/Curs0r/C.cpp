#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)


#define MAXN 100010
#define MAXE 200010

struct Edge{
    int u, v;
    ll c, f;
    Edge(){};
    Edge(int _u, int _v, ll _c, ll _f) {
        u=_u; v=_v; c=_c; f=_f;
    }
}edge[MAXE*2];
int n_edge;

VI Map[MAXN];
int last[MAXN];

void init() {
    REP(i,MAXN) Map[i].clear();
    n_edge = 0;
}

int d[MAXN];
int gap[MAXN];
int bfs(int s, int t) {
    int n = 0;
    queue<int> q;
    REP(i,MAXN) d[i] = INF;
    REP(i,MAXN) gap[i] = 0;
    d[t] = 0;
    q.push(t);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        gap[d[u]]++;
        n++;
        REP(i,Map[u].size()) {
            int e=Map[u][i];
            int v=edge[e].v;
            if(edge[e^1].f < edge[e^1].c && d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return n;
}

ll augument(int t) {
    int e = last[t];
    ll fl = INF;
    while(e != -1) {
        int v = edge[e].u;
        fl = min(fl, edge[e].c - edge[e].f);
        e = last[v];
    }
    e = last[t];
    while(e != -1) {
        int v = edge[e].u;
        edge[e].f += fl;
        edge[e^1].f -= fl;
        e = last[v];
    }
    return fl;
}

ll ISAP(int s, int t) {
    ll res = 0;
    int n = bfs(s, t);
    last[s] = -1;
    int u = s;
    while(d[s] < n) {
        if(u == t) {
            res += augument(t);
            u = s;
        }
        int f = 0;
        REP(i, Map[u].size()) {
            int e = Map[u][i];
            int v = edge[e].v;
            if(edge[e].f < edge[e].c && d[u] == d[v] + 1) {
                // advance
                u = v;
                last[v] = e;
                f = 1;
                break;
            }
        }
        if(!f) {
            // retreat
            int _min = n;
            REP(i,Map[u].size()) {
                int e = Map[u][i];
                int v = edge[e].v;
                if(edge[e].f < edge[e].c) _min = min(_min, d[v]);
            }
            if(--gap[d[u]]==0) break;
            d[u] = _min+1;
            gap[d[u]]++;
            if(u != s) u = edge[last[u]].u;
        }
    }
    return res;
}

void addEdge(int u, int v, ll c) {
    edge[n_edge] = Edge(u,v,c,0);
    Map[u].PB(n_edge++);
    edge[n_edge] = Edge(v,u,0,0);
    Map[v].PB(n_edge++);
}


int a[1000], b[1000];
int c1[1000], c2[1000];
int main()
{
#ifdef LOCAL
	   freopen("C-large.in","r",stdin);
	   freopen("C-large.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int t,cs=1;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		unordered_map<string, int> mp1, mp2;
		int cc1=0,cc2=0;
		
		init();
		REP(i,n) {
			string s1,s2;
			cin>>s1>>s2;
			if(mp1.count(s1)) {
				a[i] = mp1[s1];
			}else a[i] = mp1[s1] = cc1++;
			if(mp2.count(s2)) {
				b[i] = mp2[s2];
			}else b[i] = mp2[s2] = cc2++;
			
			addEdge(a[i], b[i]+n, 1);
		}
		int S = n*2+1;
		int T = S+1;
		REP(i,cc1) {
			addEdge(S,i,1);
		}
		REP(i,cc2) {
			addEdge(i+n,T,1);
		}
		
		cout<<"Case #"<<cs++<<": "<<n-(cc1+cc2-ISAP(S,T))<<endl;
	}
	return 0;
}


