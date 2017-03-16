//============================================================================
// Name        : GCJ2015.cpp
// Author      : Aditya Vikram Jain
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>
#include <valarray>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cassert>
#include <cstring>
#include <typeinfo>
using namespace std;


using namespace std;
typedef long long int64;
//#define long int64


//====================================================================
// Library code follows:
//.
// My Min-cost-max-flow solver:
//
const long CINF=1ll<<62;
const int       INF=1000;
const int       MAX=15*15*2+2;

struct network
{
	int source, sink;
	int n;
	bool hasNegative;
	network() { n= 0; hasNegative=false; }

	struct lowCostFirst
	{
		bool operator ()(const pair<int,long> &a, const pair<int,long> &b)
		{
			if(a.second < b.second)
				return true;
			if(a.second==b.second)
				return (a.first>b.first);
			return false;
		}
	};

	map< pair<int, long>, int, lowCostFirst > adj[MAX];
	typedef map< pair<int, long>, int, lowCostFirst >::iterator iter;

	bool visited[MAX];

	int parent[MAX];
	long distance[MAX];


	//=========
	// Dijkstra: Use set instead of priority_queue because we want it
	//           to use O(V) memory, don't we?
	//
	set< pair<long,int> > Q; //dijkstra queue
	typedef set< pair<long,int> >::iterator Qiter;
	long parentEdge[MAX];
	void allDijkstra()
	{
		fill(distance, distance+n, CINF);
		fill(parent, parent+n, -1);

		distance[source]=0;
		parent[source]=-1;
		Q.insert( make_pair(0ll, source) );
		Qiter it;
		while ( (it=Q.begin()) !=Q.end()) {
			int p= it->second;
			Q.erase(it);
			for (iter q=adj[p].begin(); q!=adj[p].end(); q++) {
				int to=q->first.first, cap=q->second;
				long edgecost=q->first.second, newdist= distance[p]+edgecost;

				if( (cap>0) && (distance[to] > newdist) ) {
					Q.erase(make_pair((long long)distance[to],to));
					Q.insert( make_pair((long long)newdist, to) );
					distance[to]=newdist;
					parent[to]=p;
					parentEdge[to]=edgecost;
				}
			}
		}
	}

	//============================================================
	// Bellman Ford: Slow but good for negative stuff
	//
	void BellmanFord()
	{
		//assert(false);

		fill(parent,parent+n,-1);
		fill(distance, distance+n, CINF);
		distance[source]=0;
		parent[source]=-1;

		set<int> changed[2];
		changed[0].insert(source);
		for (int i=0; (i<n-1) && !(changed[i&1].empty()) ;i++)
		{
			set<int>::iterator q;
			while ( (q=changed[i&1].begin()) != changed[i&1].end() ) {
				int j=*q;
				changed[i&1].erase(q);

				for (iter p = adj[j].begin(); p!=adj[j].end(); p++) if(p->second>0) {
					int k=p->first.first; long c=p->first.second;
					if( distance[j]+c < distance[k] ) {
						parent[k]=j,
								distance[k]=distance[j]+c,
								parentEdge[k]=c,
								changed[(i+1)&1].insert(k);
					}
				}
			}
		}

	}


	void minCostMaxFlow( int &flow, long &cost)
	{
		flow=0, cost=0;
		long fix=0;

		while (true) {
			//run Dijkstra/Bellman-Ford to get distances and parents
			if(hasNegative) {
				hasNegative=false;
				BellmanFord();
			} else {
				allDijkstra();
			}

			if(parent[sink]==-1) { //The sink is unreachable
				break;
			}

			int f=INF; long tcost=0;
			for (int x=sink; parent[x]!=-1; x=parent[x]) {
				tcost +=parentEdge[x];
				f = std::min(f,adj[parent[x]][ make_pair(x, parentEdge[x] ) ]);
			}

			//residual network:
			for (int x=sink; parent[x]!=-1; x=parent[x]) {
				adj[parent[x]][ make_pair(x,parentEdge[x]) ]-=f;
				pair<int, long> key= make_pair(parent[x], -parentEdge[x] );
				iter it=adj[x].find(key);
				if(it==adj[x].end()) {
					adj[x][key]=f;
				} else {
					it->second+=f;
				}
			}

			//fix edge costs using 'potentials':
			for (int i=n;i--;) {
				map< pair<int, long>, int, lowCostFirst > nm;
				for (iter q=adj[i].begin(); q!=adj[i].end(); q++) {
					pair<int,long> oldkey = q->first, newkey = oldkey;
					newkey.second += distance[i]-distance[oldkey.first];
					assert((newkey.second>=0) || (q->second==0) );
					nm[newkey]+=q->second;
				}
				adj[i]=nm;
			}

			//update vars:
			flow+=f;
			cost+=((fix+tcost)*f);
			fix+=distance[sink];
		}
	}

	void addEdge(int from, int to, int capacity, long cost)
	{
		pair<int, long> k=make_pair(to, cost);
		auto q = adj[from].find(k);
		if(q!=adj[from].end()) {
			q->second+=capacity;
		} else {
			adj[from][k]=capacity;
		}

		if(cost<0) {
			hasNegative=true;
		}
	}

	int addVertex()
	{
		assert(n<MAX);
		int r=n++;
		adj[r].clear();
		return r;
	}

};
//
// Library code has ended...
//===============================



int getMinimum(vector <string> board)
{
	int w = board.size(), h = board[0].size();
	network * G = new network();
	int in[w][h];
	int out[w][h];
	G->source = G->addVertex();
	G->sink = G->addVertex();
	for (int i=0; i<w; i++) {
		for (int j=0; j<h; j++) {
			in[i][j] = G->addVertex();
			out[i][j] = G->addVertex();
			G->addEdge(G->source, in[i][j], 1, 0);
			G->addEdge(out[i][j], G->sink, 1, 0);
		}
	}
	const string NAME = "ULDR";
	const int dx[4] = {0, -1, 0, 1};
	const int dy[4] = {-1, 0, 1, 0};

	for (int x=0; x<h; x++) {
		for (int y=0; y<w; y++) {
			for (int d=0; d<4; d++) {
				int nx = (x + dx[d] + h) % h;
				int ny = (y + dy[d] + w) % w;
				if (NAME[d] == board[y][x]) {
					G->addEdge( in[y][x], out[ny][nx], 1, 0);
				} else {
					G->addEdge( in[y][x], out[ny][nx], 1, 1);
				}
			}
		}
	}
	int flow; long cost;
	G->minCostMaxFlow(flow, cost);
	assert( flow == w*h);
	return (int)cost;
}


/*
 * GCJ problems solutions start here
 *
 *
 */

void solveA(){
	int t=1,T;
	cin>>T;
	while(t<=T){
		int R,C,W,ans;
		cin>>R>>C>>W;
		ans = (C/W)*(R-1);
		ans += (C/W) + W-1;
		if(C%W)
			ans += 1;
		cout<<"Case #"<<t<<": "<<ans<<endl;
		t++;
	}
}

void solveB(){
	int t=1,T;
	cin>>T;
	while(t<=T){

		cout<<"Case #"<<t<<": "<<"     "<<endl;
		t++;
	}
}

void solveC(){
	int t=1,T;
	cin>>T;
	while(t<=T){
		int C,D,V,tmp;
		cin>>C>>D>>V;
		vector<int> v;
		for(int i=0;i<D;i++){
			cin>>tmp;
			for(int j=0;j<C;j++)
				v.push_back(tmp);
		}
		vector<int> vals(V+1,0);
		vals[0] = 1;
		for(int i=0;i<(int)(v.size());i++){
			vector<int> valsn = vals;
			for(int j=0;j<=V;j++){
				if(vals[j]==1 && (j+v[i])<=V){
					valsn[j+v[i]] = 1;
				}
			}
			vals = valsn;
		}
		int ans = 0;
		vector<int> target = vector<int>(V+1,1);
		while(vals != target){
			int ind = 0;
			while(vals[ind] == target[ind])
				ind++;
			ans++;
			vector<int> vt;
			for(int i=0;i<C;i++){
				vt.push_back(ind);
			}
			vector<int> valsn = vals;
			for(int i=0;i<(int)vt.size();i++){
				for(int j=0;j<=V;j++){
					if(vals[j]==1 && (j+vt[i])<=V){
						valsn[j+vt[i]] = 1;
					}
				}
				vals = valsn;
			}

		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
		t++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//	solveA();
	//	solveB();
	solveC();
}
