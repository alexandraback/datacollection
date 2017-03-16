#include<iostream>
#include<vector>
#include<map>
#include<string>
#define SOURCE 0
#define LEFT (SOURCE+1)
#define RIGHT (LEFT+1000)
#define SINK (RIGHT+1000)
#define f first
#define s second
#define mp make_pair
using namespace std;


struct Edge{
	int src, dest, cap, cpart;
	
	Edge(int newSrc = 0, int newDest = 0, int newCap = 0) {
		src = newSrc;
		dest = newDest;
		cap = newCap;
	}
};




struct Graph {
	vector<vector<Edge> > conn;
	
	Graph() {
		conn.resize(SINK+1);
	}
	
	void addEdge(int a, int b, int cap = 1) {
		int aind = conn[a].size();
		conn[a].push_back(Edge(a, b, cap) );
		
		int bind = conn[b].size();
		conn[b].push_back(Edge(b, a, 0) );
		
		conn[a][aind].cpart = bind;
		conn[b][bind].cpart = aind;
	}
	
	bool flowDFS(int pos, vector<bool> &explr, vector<int> &visited) {
		if(pos == SINK)
			return true;
		
		if(explr[pos])
			return false;
		explr[pos] = true;
		visited.push_back(pos);
		
		for(auto &e : conn[pos])
			if(e.cap > 0 && flowDFS(e.dest, explr, visited) ) {
				e.cap--;
				conn[e.dest][e.cpart].cap++;
				return true;
			}
			
		return false;
	}
	
	
	
	
	int getFlow() {
		int flow = 0;
		
		vector<bool> explr(SINK+1, false);
		vector<int> visited;
		
		while(flowDFS(SOURCE, explr, visited) ) {
			for(auto c : visited)
				explr[c] = false;
			visited.clear();
			flow++;
		}
		
		return flow;
	}
	
};




//---------------------------------------------------------
//Main function


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int TCASE = 1; TCASE <= T; TCASE++) {
		Graph g;
		
		int n, lsize = 0, rsize = 0;
		cin >> n;
		
		map<string, int> left, right;
		
		for(int i=0;i<n;i++) {
			string a, b;
			cin >> a >> b;
			
			if(!left.count(a) ) {
				g.addEdge(SOURCE, LEFT + lsize);
				left[a] = lsize++;
			}
			if(!right.count(b) ) {
				g.addEdge(RIGHT + rsize, SINK);
				right[b] = rsize++;
			}
			
			g.addEdge(LEFT + left[a], RIGHT + right[b]);
		}
		
		cout << "Case #" << TCASE << ": " << n - lsize - rsize + g.getFlow() << '\n';
	}
	
	return 0;
}













































