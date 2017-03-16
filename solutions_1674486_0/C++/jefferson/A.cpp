#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

typedef vector <   int  > vi;
typedef vector <   vi   > vvi;
typedef vector < double > vd;
typedef vector <   vd   > vvd;
typedef vector < string > vs;

bool dfs (const vector<vector<int> >& adj, vector<bool> &visited, int v,
vector<bool> &marked){
	if (visited[v])
		return true;
	
	marked[v] = true;
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		if (!marked[adj[v][i]] && dfs(adj, visited, adj[v][i], marked))
			return true;
	}

	marked[v] = false;

	return false;
}

bool C2P (const vector< vector<int> >& adj, int v) {
	vector<bool> visited (adj.size(), false);
	vector<bool> marked (adj.size(), false);
	return dfs (adj, visited, v, marked);
}


int main () {
	int T, n, x; cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		vector< vector< int > > g (N, *new vector<int>());
		
		for (int i = 0; i < N; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				cin >> x;
				g[i].push_back(x-1);
			}
		}

		bool find = false;
		for (int i = 0; i < N; i++) {
			if ( C2P(g, i) ) {
				find = true;
				break;
			}
		}
		
		cout << "Case #"<< t << ": " << (find ? "Yes" : "No") << endl;
	}

	return 0;
}
