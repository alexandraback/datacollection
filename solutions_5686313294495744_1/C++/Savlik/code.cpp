#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>
#include <unordered_map>
#include <valarray>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define ROF(i,n) for (ll i = ((ll)n-1); i >= 0; i--)
#define FOR1(i,n) for (ll i = 1; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) ll a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) FOR(i,sz(v))cout<<v[i]<<" ";
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define oo ((1LL<<62)+((1LL<<31)-1))
#define MOD 1000000007ll
const double PI = std::atan(1.0)*4;

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//#include <windows.h>
//#include <thread>
//#include <chrono>

//set orinted graph by .add_edge(from, to, capacity)
//find_flow() will find max flow in graph in time O(|V| * |E|)

#define MAX_NODES 20010

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define oo 1000000000

class Edge{
public:
	int from, to;
	int capacity, flow;

	Edge(int _from, int _to, int _capacity = 1){
		from = _from;
		to = _to;
		capacity = _capacity;
		flow = 0;
	}
};

class MaxFlow{
public:
	int n;  // number of nodes
	vector<vector<Edge*> > edge_out, edge_in;
	int color[MAX_NODES]; // needed for breadth-first search               
	pair<Edge*, int> pred[MAX_NODES];  // array to store augmenting path
	queue<int> q;  //queue for BFS
	int max_flow;  //computed by find_flow

	MaxFlow(int nn){
		n = nn;
		edge_out = vector<vector<Edge*> >(n);
		edge_in = vector<vector<Edge*> >(n);
	}

	MaxFlow(){
		n = MAX_NODES;
		edge_out = vector<vector<Edge*> >(n);
		edge_in = vector<vector<Edge*> >(n);
	}

	~MaxFlow(){
		FOR(i, sz(edge_out)){
			FOR(j, sz(edge_out[i])){
				delete edge_out[i][j];
			}
		}
	}

	void add_edge(int from, int to, int cap = 1){
		Edge* e = new Edge(from, to, cap);
		edge_out[from].pb(e);
		edge_in[to].pb(e);
	}


	int bfs (int start, int target) { 
		int u,v;
		for(int i=0;i<n;i++) color[i] = WHITE;
		q.push(start);
		color[start] = GRAY;
		//pred[start] = mp(NULL, -1);
		while (!q.empty()) {
			u = q.front(); q.pop();
			color[u] = BLACK;
			if(u == target){
				while(!q.empty()) q.pop();
				break;
			}
			// Search all adjacent white nodes v. If the capacity
			// from u to v in the residual network is positive, enqueue v.
			for (int i=0; i < edge_out[u].size(); i++){
				v = edge_out[u][i]->to;
				if (color[v]==WHITE && edge_out[u][i]->capacity - edge_out[u][i]->flow > 0) {
					q.push(v); 
					color[v] = GRAY;
					pred[v] = mp(edge_out[u][i], 0);
				}
			}

			for (int i=0; i < edge_in[u].size(); i++){
				v = edge_in[u][i]->from;
				if (color[v]==WHITE && edge_in[u][i]->flow > 0) {
					q.push(v); 
					color[v] = GRAY;
					pred[v] = mp(edge_in[u][i], 1);
				}
			}

		}
		// If the color of the target node is black now, it means that we reached it.
		return color[target]==BLACK;
	}

	void find_flow (int source, int sink) {
		max_flow = 0;
		int u;
		FOR(i, sz(edge_out)){
			FOR(j, sz(edge_out[i])){
				edge_out[i][j]->flow = 0;
			}
		}
		// While there exists an augmenting path,
		// increment the flow along this path.
		while (bfs(source,sink)) {
			// Determine the amount by which we can increment the flow.
			int increment = oo;
			u = sink;
			while(u!=source){
				if(pred[u].ss == 0){
					increment = std::min(increment, pred[u].ff->capacity - pred[u].ff->flow);
					u = pred[u].ff->from;
				}else{
					increment = std::min(increment, pred[u].ff->flow);
					u = pred[u].ff->to;
				}
			}
			// Now increment the flow.
			u = sink;
			while(u!=source){
				if(pred[u].ss == 0){
					pred[u].ff->flow += increment;
					u = pred[u].ff->from;
				}else{
					pred[u].ff->flow -= increment;
					u = pred[u].ff->to;
				}
			}
			max_flow += increment;
		}
		// No augmenting path anymore. We are done.
	}
};

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	FOR(t, T){
		ll res = 0;
		int n;
		cin>>n;
		map<string, int> a,b;
		vpii edges;
		FOR(i, n){
			string s, r;
			cin>>s>>r;
			int x,y;
			if(a.find(s)!=a.end()){
				x=a[s];
			}else{
				x=a.size();
				a[s]=x;
			}
			if(b.find(r)!=b.end()){
				y=b[r];
			}else{
				y=b.size();
				b[r]=y;
			}
			edges.pb(mp(x,y));
		}
		int k=a.size();
		int l=b.size();
		vector<int>c1(k, -1);
		vector<int>c2(l, -1);
		FOR(i, sz(edges)){
			c1[edges[i].ff]++;
			c2[edges[i].ss]++;
		}

		MaxFlow mf;
		FOR(i, sz(edges)){
			int x = edges[i].ff;
			int y = edges[i].ss;
			mf.add_edge(k+x, y+2*k, 1);
		}
		FOR(i, k){
			
			mf.add_edge(i, k+i, c1[i]);
			mf.add_edge(2*k+2*l+1, i, 10000);
		}
		FOR(i, l){
			
			mf.add_edge(2*k+i, 2*k+l+i, c2[i]);
			mf.add_edge(2*k+l+i, 2*k+2*l+2, 10000);
		}
		mf.find_flow(2*k+2*l+1, 2*k+2*l+2);

		cout<<"Case #"<<(t+1)<<": "<<mf.max_flow<<endl;
		
	}
	return 0;
}