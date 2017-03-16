#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct Edge{
    int from, to, c, flow;

    Edge(int _from, int _to, int _c, int _flow);
};

struct Graph{

    vector<Edge> edges;

    Graph(int numNodes);

    void AddEdge(int from, int to, int c);
    
    void AddEdge(int from, int to, int c, int flow);

    int MinCut(int s, int t);

    private:
    // Contains all edges that go to and from each node, respectively
    vector<vector<int> > edgesIn, edgesOut;

    void dfs(int node, set<int>* vertexSet);
};

Edge::Edge(int _from, int _to, int _c, int _flow) : from(_from), to(_to), c(_c), flow(_flow){
}

Graph::Graph(int numNodes){
    edgesIn = vector<vector<int> >(numNodes);
    edgesOut = vector<vector<int> >(numNodes);
}

void Graph::AddEdge(int from, int to, int c){
    AddEdge(from, to, c, 0);
}

void Graph::AddEdge(int from, int to, int c, int flow){
    Edge edge(from, to, c, flow);
    edges.push_back(edge);
    edgesOut[from].push_back(edges.size()-1);
    edgesIn[to].push_back(edges.size()-1);
}

int Graph::MinCut(int s, int t){
    int N=edgesIn.size();
    int totalFlow = 0;
    while(true){
        vector<int> flowTo(N, 0);
        vector<bool> vis(N, false);
        vector<Edge*> parent(N);
        flowTo[s]=INF;
        priority_queue<pair<int, int> > pq;
        pq.push(make_pair(flowTo[s], s));
        vector<int> v;
        while(!pq.empty()){
            int cur=pq.top().second;
            if(cur == t)
                break;
            pq.pop();
            if(vis[cur])
                continue;
            v.push_back(cur);
            vis[cur]=true;
            for(int i=0; i < (int)edgesOut[cur].size(); ++i){
                Edge* edge=&edges[edgesOut[cur][i]];
                int f=min(flowTo[cur], edge->c-edge->flow);
                if(f > flowTo[edge->to]){
                    flowTo[edge->to]=f;
                    parent[edge->to]=edge;
                    pq.push(make_pair(f, edge->to));
                }
            }
            for(int i=0; i < (int)edgesIn[cur].size(); ++i){
                Edge* edge=&edges[edgesIn[cur][i]];
                int f=min(flowTo[cur], edge->flow);
                if(f > flowTo[edge->from]){
                    flowTo[edge->from]=f;
                    parent[edge->from]=edge;
                    pq.push(make_pair(f, edge->from));
                }
            }
        }
        if(!flowTo[t]){
            return totalFlow;
        }
        totalFlow += flowTo[t];
        int cur=t;
        while(cur != s){
            Edge* edge=parent[cur];
            if(edge->to == cur){
                edge->flow += flowTo[t];
                cur=edge->from;
            }
            else{
                edge->flow -= flowTo[t];
                cur=edge->to;
            }
        }
    }
    return totalFlow;
}

void solve(){
	int N;
	scanf("%d", &N);
	map<string, int> M[2];
	vector<pair<int, int> > v;
	rep(i,0,N){
		int ind[2];
		rep(j,0,2){
			string s;
			cin >> s;
			if(M[j].count(s)){
				ind[j]=M[j][s];
			}
			else{
				ind[j]=M[j].size();
				M[j][s]=ind[j];
			}
		}
		v.emplace_back(ind[0], ind[1]);
	}
	Graph g(2+M[0].size()+M[1].size());
	rep(i,0,M[0].size()){
		g.AddEdge(0, i+2, 1);
	}
	rep(i,0,M[1].size()){
		g.AddEdge(M[0].size()+2+i, 1, 1);
	}
	rep(i,0,N){
		g.AddEdge(v[i].first+2, v[i].second+2+M[0].size(), 1);
	}
	int mincut=g.MinCut(0, 1);
	int cheaters=N;
	cheaters -= mincut;
	cheaters -= (M[0].size()+M[1].size()-mincut*2);
	printf("%d\n", cheaters);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
}
